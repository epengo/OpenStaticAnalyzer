/*
 *  This file is part of OpenStaticAnalyzer.
 *
 *  Copyright (c) 2004-2017 Department of Software Engineering - University of Szeged
 *
 *  Licensed under Version 1.2 of the EUPL (the "Licence");
 *
 *  You may not use this work except in compliance with the Licence.
 *
 *  You may obtain a copy of the Licence in the LICENSE file or at:
 *
 *  https://joinup.ec.europa.eu/software/page/eupl
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the Licence is distributed on an "AS IS" basis,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the Licence for the specific language governing permissions and
 *  limitations under the Licence.
 */

#include "python/inc/python.h"
#include "python/inc/Common.h"
#include "common/inc/WriteMessage.h"

#include "python/inc/messages.h"
#include <algorithm>
#include <string.h>
#include "common/inc/math/common.h"


namespace columbus { namespace python { namespace asg {

typedef boost::crc_32_type  Crc_type;

namespace base { 
  Docstring::Docstring(NodeId _id, Factory *_factory) :
    Positioned(_id, _factory),
    m_text(0)
  {
  }

  Docstring::~Docstring() {
  }

  void Docstring::prepareDelete(bool tryOnVirtualParent){
    base::Positioned::prepareDelete(false);
  }

  NodeKind Docstring::getNodeKind() const {
    return ndkDocstring;
  }

  Key Docstring::getTextKey() const {
    return m_text;
  }

  const std::string& Docstring::getText() const {
    return factory->getStringTable().get(m_text);
  }

  void Docstring::setTextKey(Key _text) {
    m_text = _text;
  }

  void Docstring::setText(const std::string& _text) {
    m_text = factory->getStringTable().set(_text);
  }

  bool Docstring::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (base::Positioned::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool Docstring::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (base::Positioned::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  void Docstring::accept(Visitor &visitor) const {
    visitor.visit(*this);
  }

  void Docstring::acceptEnd(Visitor &visitor) const {
    visitor.visitEnd(*this);
  }

  double Docstring::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      const Docstring& node = dynamic_cast<const Docstring&>(base);
      double matchAttrs = 0;
      std::string str1, str2;
      size_t strMax;
      double strSim;
      str1 = getText();
      str2 = node.getText();
      strMax = std::max(str1.size(), str2.size());
      strSim = 1 - ((double)common::math::editDistance(str1, str2) / (strMax > 0 ? strMax : 1));
      if (strSim < Common::SimilarityMinForStrings)
        return 0.0;
      matchAttrs += strSim;
      return matchAttrs / (1 / (1 - Common::SimilarityMinimum)) + Common::SimilarityMinimum;
    } else {
      return 0.0;
    }
  }

  void Docstring::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

    foundKeyId = oldAndNewStrKeyMap.find(m_text);
    if (foundKeyId != oldAndNewStrKeyMap.end()) {
      m_text = foundKeyId->second;
    } else {
      Key oldkey = m_text;
      m_text = newStrTable.set(factory->getStringTable().get(m_text));
      oldAndNewStrKeyMap.insert(std::pair<Key,Key>(oldkey,m_text));    }

  }

  NodeHashType Docstring::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "base::Docstring", strlen("base::Docstring"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void Docstring::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    Positioned::save(binIo,false);

    factory->getStringTable().setType(m_text, StrTable::strToSave);
    binIo.writeUInt4(m_text);

  }

  void Docstring::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    Positioned::load(binIo,false);

    m_text = binIo.readUInt4();

  }


}


}}}
