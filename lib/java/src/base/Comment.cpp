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

#include "java/inc/java.h"
#include "java/inc/Common.h"
#include "common/inc/WriteMessage.h"

#include "java/inc/messages.h"
#include <algorithm>
#include <string.h>
#include "common/inc/math/common.h"
#include <sstream>


namespace columbus { namespace java { namespace asg {

typedef boost::crc_32_type  Crc_type;

namespace base { 
  Comment::Comment(NodeId _id, Factory *_factory) :
         Base(_id, _factory),
    PositionedWithoutComment(_id, _factory),
    m_text(0)
  {
  }

  Comment::~Comment() {
  }

  void Comment::clone(const Comment& other, bool tryOnVirtualParent) {
    if (tryOnVirtualParent) {
      base::Base::clone(other, false);
    }
    base::PositionedWithoutComment::clone(other, false);

    m_text = other.m_text;
  }

  void Comment::prepareDelete(bool tryOnVirtualParent){
    if (tryOnVirtualParent) {
      base::Base::prepareDelete(false);
    }
    base::PositionedWithoutComment::prepareDelete(false);
  }

  Key Comment::getTextKey() const {
    return m_text;
  }

  const std::string& Comment::getText() const {
    return factory->getStringTable().get(m_text);
  }

  void Comment::setTextKey(Key _text) {
    m_text = _text;
  }

  void Comment::setText(const std::string& _text) {
    m_text = factory->getStringTable().set(_text);
  }

  bool Comment::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (tryOnVirtualParent) {
      if (base::Base::setEdge(edgeKind, edgeEnd, false)) {
        return true;
      }
    }
    if (base::PositionedWithoutComment::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool Comment::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (tryOnVirtualParent) {
      if (base::Base::removeEdge(edgeKind, edgeEnd, false)) {
        return true;
      }
    }
    if (base::PositionedWithoutComment::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  double Comment::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      const Comment& node = dynamic_cast<const Comment&>(base);
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

  void Comment::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

    foundKeyId = oldAndNewStrKeyMap.find(m_text);
    if (foundKeyId != oldAndNewStrKeyMap.end()) {
      m_text = foundKeyId->second;
    } else {
      Key oldkey = m_text;
      m_text = newStrTable.set(factory->getStringTable().get(m_text));
      oldAndNewStrKeyMap.insert(std::pair<Key,Key>(oldkey,m_text));    }

  }

  NodeHashType Comment::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "base::Comment", strlen("base::Comment"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void Comment::sort(bool withVirtualBase /* = true */) {
    if (withVirtualBase)
      Base::sort(false);
    PositionedWithoutComment::sort(false);
  }

  void Comment::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    if (withVirtualBase)
      Base::save(binIo,false);

    PositionedWithoutComment::save(binIo,false);

    factory->getStringTable().setType(m_text, StrTable::strToSave);
    binIo.writeUInt4(m_text);

  }

  void Comment::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    if (withVirtualBase)
      Base::load(binIo, false);

    PositionedWithoutComment::load(binIo,false);

    m_text = binIo.readUInt4();

  }


}


}}}
