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

namespace type { 
  DictType::DictType(NodeId _id, Factory *_factory) :
    Type(_id, _factory)
  {
  }

  DictType::~DictType() {
  }

  void DictType::prepareDelete(bool tryOnVirtualParent){
    type::Type::prepareDelete(false);
  }

  NodeKind DictType::getNodeKind() const {
    return ndkDictType;
  }

  bool DictType::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (type::Type::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool DictType::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (type::Type::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  void DictType::accept(Visitor &visitor) const {
    visitor.visit(*this);
  }

  void DictType::acceptEnd(Visitor &visitor) const {
    visitor.visitEnd(*this);
  }

  double DictType::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      return 1.0;
    } else {
      return 0.0;
    }
  }

  void DictType::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

  }

  NodeHashType DictType::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "type::DictType", strlen("type::DictType"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void DictType::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    Type::save(binIo,false);

  }

  void DictType::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    Type::load(binIo,false);

  }


}


}}}
