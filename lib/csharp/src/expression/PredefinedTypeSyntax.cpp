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

#include "csharp/inc/csharp.h"
#include "csharp/inc/Common.h"
#include "common/inc/WriteMessage.h"

#include "csharp/inc/messages.h"
#include <algorithm>
#include <string.h>
#include "common/inc/math/common.h"


namespace columbus { namespace csharp { namespace asg {

typedef boost::crc_32_type  Crc_type;

namespace expression { 
  PredefinedTypeSyntax::PredefinedTypeSyntax(NodeId _id, Factory *_factory) :
    TypeSyntax(_id, _factory)
  {
  }

  PredefinedTypeSyntax::~PredefinedTypeSyntax() {
  }

  void PredefinedTypeSyntax::prepareDelete(bool tryOnVirtualParent){
    expression::TypeSyntax::prepareDelete(false);
  }

  NodeKind PredefinedTypeSyntax::getNodeKind() const {
    return ndkPredefinedTypeSyntax;
  }

  bool PredefinedTypeSyntax::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (expression::TypeSyntax::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool PredefinedTypeSyntax::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    if (expression::TypeSyntax::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  void PredefinedTypeSyntax::accept(Visitor &visitor) const {
    visitor.visit(*this);
  }

  void PredefinedTypeSyntax::acceptEnd(Visitor &visitor) const {
    visitor.visitEnd(*this);
  }

  double PredefinedTypeSyntax::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      return 1.0;
    } else {
      return 0.0;
    }
  }

  void PredefinedTypeSyntax::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

      m_position.swapStringTable(newStrTable,oldAndNewStrKeyMap);

  }

  NodeHashType PredefinedTypeSyntax::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "expression::PredefinedTypeSyntax", strlen("expression::PredefinedTypeSyntax"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void PredefinedTypeSyntax::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    TypeSyntax::save(binIo,false);

  }

  void PredefinedTypeSyntax::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    TypeSyntax::load(binIo,false);

  }


}


}}}
