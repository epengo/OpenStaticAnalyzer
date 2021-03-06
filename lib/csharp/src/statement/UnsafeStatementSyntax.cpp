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

namespace statement { 
  UnsafeStatementSyntax::UnsafeStatementSyntax(NodeId _id, Factory *_factory) :
    StatementSyntax(_id, _factory),
    m_Block(0)
  {
  }

  UnsafeStatementSyntax::~UnsafeStatementSyntax() {
  }

  void UnsafeStatementSyntax::prepareDelete(bool tryOnVirtualParent){
    removeBlock();
    statement::StatementSyntax::prepareDelete(false);
  }

  NodeKind UnsafeStatementSyntax::getNodeKind() const {
    return ndkUnsafeStatementSyntax;
  }

  statement::BlockSyntax* UnsafeStatementSyntax::getBlock() const {
    statement::BlockSyntax *_node = NULL;
    if (m_Block != 0)
      _node = dynamic_cast<statement::BlockSyntax*>(factory->getPointer(m_Block));
    if ( (_node == NULL) || factory->getIsFiltered(_node))
      return NULL;

    return _node;
  }

  bool UnsafeStatementSyntax::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    switch (edgeKind) {
      case edkUnsafeStatementSyntax_Block:
        setBlock(edgeEnd);
        return true;
      default:
        break;
    }
    if (statement::StatementSyntax::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool UnsafeStatementSyntax::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    switch (edgeKind) {
      case edkUnsafeStatementSyntax_Block:
        removeBlock();
        return true;
      default:
        break;
    }
    if (statement::StatementSyntax::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  void UnsafeStatementSyntax::setBlock(NodeId _id) {
    statement::BlockSyntax *_node = NULL;
    if (_id) {
      if (!factory->getExist(_id))
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_THE_END_POINT_OF_THE_EDGE_DOES_NOT_EXIST);

      _node = dynamic_cast<statement::BlockSyntax*> (factory->getPointer(_id));
      if ( _node == NULL) {
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_INVALID_NODE_KIND);
      }
      if (&(_node->getFactory()) != this->factory)
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_THE_FACTORY_OF_NODES_DOES_NOT_MATCH );

      if (m_Block) {
        removeParentEdge(m_Block);
        if (factory->getExistsReverseEdges())
          factory->reverseEdges->removeEdge(m_Block, m_id, edkUnsafeStatementSyntax_Block);
      }
      m_Block = _node->getId();
      if (m_Block != 0)
        setParentEdge(factory->getPointer(m_Block), edkUnsafeStatementSyntax_Block);
      if (factory->getExistsReverseEdges())
        factory->reverseEdges->insertEdge(m_Block, this->getId(), edkUnsafeStatementSyntax_Block);
    } else {
      if (m_Block) {
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_CAN_T_SET_EDGE_TO_NULL);
      }
    }
  }

  void UnsafeStatementSyntax::setBlock(statement::BlockSyntax *_node) {
    if (_node == NULL)
      throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_CAN_T_SET_EDGE_TO_NULL);

    setBlock(_node->getId());
  }

  void UnsafeStatementSyntax::removeBlock() {
      if (m_Block) {
        removeParentEdge(m_Block);
        if (factory->getExistsReverseEdges())
          factory->reverseEdges->removeEdge(m_Block, m_id, edkUnsafeStatementSyntax_Block);
      }
      m_Block = 0;
  }

  void UnsafeStatementSyntax::accept(Visitor &visitor) const {
    visitor.visit(*this);
  }

  void UnsafeStatementSyntax::acceptEnd(Visitor &visitor) const {
    visitor.visitEnd(*this);
  }

  double UnsafeStatementSyntax::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      return 1.0;
    } else {
      return 0.0;
    }
  }

  void UnsafeStatementSyntax::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

      m_position.swapStringTable(newStrTable,oldAndNewStrKeyMap);

  }

  NodeHashType UnsafeStatementSyntax::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "statement::UnsafeStatementSyntax", strlen("statement::UnsafeStatementSyntax"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void UnsafeStatementSyntax::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    StatementSyntax::save(binIo,false);

    binIo.writeUInt4(m_Block);

  }

  void UnsafeStatementSyntax::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    StatementSyntax::load(binIo,false);

    m_Block =  binIo.readUInt4();
    if (m_Block != 0)
      setParentEdge(factory->getPointer(m_Block),edkUnsafeStatementSyntax_Block);

  }


}


}}}
