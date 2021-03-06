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

namespace structure { 
  XmlProcessingInstructionSyntax::XmlProcessingInstructionSyntax(NodeId _id, Factory *_factory) :
    XmlNodeSyntax(_id, _factory),
    m_Name(0)
  {
  }

  XmlProcessingInstructionSyntax::~XmlProcessingInstructionSyntax() {
  }

  void XmlProcessingInstructionSyntax::prepareDelete(bool tryOnVirtualParent){
    removeName();
    structure::XmlNodeSyntax::prepareDelete(false);
  }

  NodeKind XmlProcessingInstructionSyntax::getNodeKind() const {
    return ndkXmlProcessingInstructionSyntax;
  }

  structure::XmlNameSyntax* XmlProcessingInstructionSyntax::getName() const {
    structure::XmlNameSyntax *_node = NULL;
    if (m_Name != 0)
      _node = dynamic_cast<structure::XmlNameSyntax*>(factory->getPointer(m_Name));
    if ( (_node == NULL) || factory->getIsFiltered(_node))
      return NULL;

    return _node;
  }

  bool XmlProcessingInstructionSyntax::setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    switch (edgeKind) {
      case edkXmlProcessingInstructionSyntax_Name:
        setName(edgeEnd);
        return true;
      default:
        break;
    }
    if (structure::XmlNodeSyntax::setEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  bool XmlProcessingInstructionSyntax::removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent) {
    switch (edgeKind) {
      case edkXmlProcessingInstructionSyntax_Name:
        removeName();
        return true;
      default:
        break;
    }
    if (structure::XmlNodeSyntax::removeEdge(edgeKind, edgeEnd, false)) {
      return true;
    }
    return false;
  }

  void XmlProcessingInstructionSyntax::setName(NodeId _id) {
    structure::XmlNameSyntax *_node = NULL;
    if (_id) {
      if (!factory->getExist(_id))
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_THE_END_POINT_OF_THE_EDGE_DOES_NOT_EXIST);

      _node = dynamic_cast<structure::XmlNameSyntax*> (factory->getPointer(_id));
      if ( _node == NULL) {
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_INVALID_NODE_KIND);
      }
      if (&(_node->getFactory()) != this->factory)
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_THE_FACTORY_OF_NODES_DOES_NOT_MATCH );

      if (m_Name) {
        removeParentEdge(m_Name);
        if (factory->getExistsReverseEdges())
          factory->reverseEdges->removeEdge(m_Name, m_id, edkXmlProcessingInstructionSyntax_Name);
      }
      m_Name = _node->getId();
      if (m_Name != 0)
        setParentEdge(factory->getPointer(m_Name), edkXmlProcessingInstructionSyntax_Name);
      if (factory->getExistsReverseEdges())
        factory->reverseEdges->insertEdge(m_Name, this->getId(), edkXmlProcessingInstructionSyntax_Name);
    } else {
      if (m_Name) {
        throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_CAN_T_SET_EDGE_TO_NULL);
      }
    }
  }

  void XmlProcessingInstructionSyntax::setName(structure::XmlNameSyntax *_node) {
    if (_node == NULL)
      throw CsharpException(COLUMBUS_LOCATION, CMSG_EX_CAN_T_SET_EDGE_TO_NULL);

    setName(_node->getId());
  }

  void XmlProcessingInstructionSyntax::removeName() {
      if (m_Name) {
        removeParentEdge(m_Name);
        if (factory->getExistsReverseEdges())
          factory->reverseEdges->removeEdge(m_Name, m_id, edkXmlProcessingInstructionSyntax_Name);
      }
      m_Name = 0;
  }

  void XmlProcessingInstructionSyntax::accept(Visitor &visitor) const {
    visitor.visit(*this);
  }

  void XmlProcessingInstructionSyntax::acceptEnd(Visitor &visitor) const {
    visitor.visitEnd(*this);
  }

  double XmlProcessingInstructionSyntax::getSimilarity(const base::Base& base){
    if(base.getNodeKind() == getNodeKind()) {
      return 1.0;
    } else {
      return 0.0;
    }
  }

  void XmlProcessingInstructionSyntax::swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap ){
    std::map<Key,Key>::iterator foundKeyId;

      m_position.swapStringTable(newStrTable,oldAndNewStrKeyMap);

  }

  NodeHashType XmlProcessingInstructionSyntax::getHash(std::set<NodeId>& travNodes) const {
    if (hashOk) return nodeHashCache;
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_BEGIN,this->getId()); 
    if (travNodes.count(getId())>0) {
      common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_SKIP);
      return 0;
    }
    travNodes.insert(getId());
    Crc_type resultHash;
    resultHash.process_bytes( "structure::XmlProcessingInstructionSyntax", strlen("structure::XmlProcessingInstructionSyntax"));
    common::WriteMsg::write(CMSG_GET_THE_NODE_HASH_OF_NODE_END,resultHash.checksum()); 
    nodeHashCache = resultHash.checksum();
    hashOk = true;
    return nodeHashCache;
  }

  void XmlProcessingInstructionSyntax::save(io::BinaryIO &binIo,bool withVirtualBase  /*= true*/) const {
    XmlNodeSyntax::save(binIo,false);

    binIo.writeUInt4(m_Name);

  }

  void XmlProcessingInstructionSyntax::load(io::BinaryIO &binIo, bool withVirtualBase /*= true*/) {
    XmlNodeSyntax::load(binIo,false);

    m_Name =  binIo.readUInt4();
    if (m_Name != 0)
      setParentEdge(factory->getPointer(m_Name),edkXmlProcessingInstructionSyntax_Name);

  }


}


}}}
