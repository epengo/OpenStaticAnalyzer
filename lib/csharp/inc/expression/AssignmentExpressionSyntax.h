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

#ifndef _CSHARP_AssignmentExpressionSyntax_H_
#define _CSHARP_AssignmentExpressionSyntax_H_

#include "csharp/inc/csharp.h"

/**
* \file AssignmentExpressionSyntax.h
* \brief Contains declaration of the expression::AssignmentExpressionSyntax class.
* \brief The it get atributes from 
*/

namespace columbus { namespace csharp { namespace asg {
namespace expression {

  /**
  * \brief AssignmentExpressionSyntax class, which represents the expression::AssignmentExpressionSyntax node.
  * (missing)
  * 
  * Edges:
  *   - EventAccessorCall (structure::AccessorDeclarationSyntax, single) : (missing)
  *   - Left (expression::ExpressionSyntax, single) : (missing)
  *   - OverloadedOperatorCall (structure::OperatorDeclarationSyntax, single) : (missing)
  *   - Right (expression::ExpressionSyntax, single) : (missing)
  */
  class AssignmentExpressionSyntax : public ExpressionSyntax {
    protected:
      /**
      * \internal
      * \brief Non-public constructor, only factory can instantiates nodes.
      * \param nodeId  [in] The id of the node.
      * \param factory [in] Poiter to the Factory the node belongs to.
      */
      AssignmentExpressionSyntax(NodeId nodeId, Factory *factory);

      /**
      * \internal
      * \brief Non-public destructor, only factory can destroy nodes.
      */
      virtual ~AssignmentExpressionSyntax();

    private:
      /**
      * \brief This function always throws a CsharpException due to copying is not allowed!
      */
      AssignmentExpressionSyntax & operator=(const AssignmentExpressionSyntax&);

      /**
      * \brief This function always throws a CsharpException due to copying is not allowed!
      */
      AssignmentExpressionSyntax(const AssignmentExpressionSyntax&);

    public:
      /**
      * \brief Gives back the NodeKind of the node.
      * \return Returns with the NodeKind.
      */
      virtual NodeKind getNodeKind() const;

      /**
      * \brief Delete all edge.
      */
      virtual void prepareDelete(bool tryOnVirtualParent);

    protected:
      /**
      * \brief Set or add the edge by edge kind
      * \param edgeKind           [in] The kind of the edge.
      * \param edgeEnd            [in] The id of node which is on the end of the edge.
      * \param tryOnVirtualParent [in] This is help for the traversal.
      * \return Return true if setting was success.
      */
      virtual bool setEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent);

    protected:
      /**
      * \brief Remove the edge by edge kind
      * \param edgeKind           [in] The kind of the edge.
      * \param edgeEnd            [in] The id of node which is on the end of the edge.
      * \param tryOnVirtualParent [in] This is help for the traversal.
      * \return Return true if removing was success.
      */
      virtual bool removeEdge(EdgeKind edgeKind, NodeId edgeEnd, bool tryOnVirtualParent);

    public:

      // ---------- Edge getter function(s) ----------

      /**
      * \brief Gives back the pointer of the node the EventAccessorCall edge points to.
      * \return Returns the end point of the EventAccessorCall edge.
      */
      structure::AccessorDeclarationSyntax* getEventAccessorCall() const;

      /**
      * \brief Gives back the pointer of the node the Left edge points to.
      * \return Returns the end point of the Left edge.
      */
      expression::ExpressionSyntax* getLeft() const;

      /**
      * \brief Gives back the pointer of the node the OverloadedOperatorCall edge points to.
      * \return Returns the end point of the OverloadedOperatorCall edge.
      */
      structure::OperatorDeclarationSyntax* getOverloadedOperatorCall() const;

      /**
      * \brief Gives back the pointer of the node the Right edge points to.
      * \return Returns the end point of the Right edge.
      */
      expression::ExpressionSyntax* getRight() const;


      // ---------- Edge setter function(s) ----------

      /**
      * \brief Sets the EventAccessorCall edge.
      * \param id [in] The new end point of the EventAccessorCall edge.
      */
      void setEventAccessorCall(NodeId id);

      /**
      * \brief Sets the EventAccessorCall edge.
      * \param node [in] The new end point of the EventAccessorCall edge.
      */
      void setEventAccessorCall(structure::AccessorDeclarationSyntax *node);

      /**
      * \brief remove the EventAccessorCall edge.
      */
      void removeEventAccessorCall();

      /**
      * \brief Sets the Left edge.
      * \param id [in] The new end point of the Left edge.
      */
      void setLeft(NodeId id);

      /**
      * \brief Sets the Left edge.
      * \param node [in] The new end point of the Left edge.
      */
      void setLeft(ExpressionSyntax *node);

      /**
      * \brief remove the Left edge.
      */
      void removeLeft();

      /**
      * \brief Sets the OverloadedOperatorCall edge.
      * \param id [in] The new end point of the OverloadedOperatorCall edge.
      */
      void setOverloadedOperatorCall(NodeId id);

      /**
      * \brief Sets the OverloadedOperatorCall edge.
      * \param node [in] The new end point of the OverloadedOperatorCall edge.
      */
      void setOverloadedOperatorCall(structure::OperatorDeclarationSyntax *node);

      /**
      * \brief remove the OverloadedOperatorCall edge.
      */
      void removeOverloadedOperatorCall();

      /**
      * \brief Sets the Right edge.
      * \param id [in] The new end point of the Right edge.
      */
      void setRight(NodeId id);

      /**
      * \brief Sets the Right edge.
      * \param node [in] The new end point of the Right edge.
      */
      void setRight(ExpressionSyntax *node);

      /**
      * \brief remove the Right edge.
      */
      void removeRight();

    protected:

      // ---------- Edges ----------

      /** \internal \brief The id of the node the EventAccessorCall edge points to. */
      NodeId m_EventAccessorCall;

      /** \internal \brief The id of the node the Left edge points to. */
      NodeId m_Left;

      /** \internal \brief The id of the node the OverloadedOperatorCall edge points to. */
      NodeId m_OverloadedOperatorCall;

      /** \internal \brief The id of the node the Right edge points to. */
      NodeId m_Right;

    public:

      // ---------- Accept fundtions for Visitor ----------

      /**
      * \brief It calls the appropriate visit method of the given visitor.
      * \param visitor [in] The used visitor.
      */
      virtual void accept(Visitor& visitor) const;

      /**
      * \brief It calls the appropriate visitEnd method of the given visitor.
      * \param visitor [in] The used visitor.
      */
      virtual void acceptEnd(Visitor& visitor) const;

      /**
      * \internal
      * \brief Calculate node similarity.
      * \param nodeIf [in] The other node.
      */
      virtual double getSimilarity(const base::Base& node);

      /**
      * \internal
      * \brief Calculate node hash.
      */
      virtual NodeHashType getHash(std::set<NodeId>&  node) const ;

    protected:
      /**
      * \internal
      * \brief It is swap the string table ids to the other string table.
      * \param newStrTable [in] The new table
      * \param oldAndNewStrKeyMap [in] The map for fast serch.
      */
      virtual void swapStringTable(RefDistributorStrTable& newStrTable, std::map<Key,Key>& oldAndNewStrKeyMap );

      /**
      * \internal
      * \brief Saves the node.
      * \param io [in] The node is written into io.
      */
      virtual void save(io::BinaryIO &io, bool withVirtualBase = true) const;

      /**
      * \internal
      * \brief Loads the node.
      * \param io [in] The node is read from io.
      */
      virtual void load(io::BinaryIO &io, bool withVirtualBase = true);


      friend class csharp::asg::Factory;
      friend class csharp::asg::VisitorSave;
  };

} 


}}}
#endif

