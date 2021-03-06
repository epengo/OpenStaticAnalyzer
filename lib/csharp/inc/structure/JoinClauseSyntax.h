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

#ifndef _CSHARP_JoinClauseSyntax_H_
#define _CSHARP_JoinClauseSyntax_H_

#include "csharp/inc/csharp.h"

/**
* \file JoinClauseSyntax.h
* \brief Contains declaration of the structure::JoinClauseSyntax class.
* \brief The it get atributes from 
*/

namespace columbus { namespace csharp { namespace asg {
namespace structure {

  /**
  * \brief JoinClauseSyntax class, which represents the structure::JoinClauseSyntax node.
  * (missing)
  * 
  * Attributes:
  *   - identifier (String) : (missing)
  * 
  * Edges:
  *   - InExpression (expression::ExpressionSyntax, single) : (missing)
  *   - Into (structure::JoinIntoClauseSyntax, single) : (missing)
  *   - LeftExpression (expression::ExpressionSyntax, single) : (missing)
  *   - RightExpression (expression::ExpressionSyntax, single) : (missing)
  *   - Type (expression::TypeSyntax, single) : (missing)
  */
  class JoinClauseSyntax : public QueryClauseSyntax {
    protected:
      /**
      * \internal
      * \brief Non-public constructor, only factory can instantiates nodes.
      * \param nodeId  [in] The id of the node.
      * \param factory [in] Poiter to the Factory the node belongs to.
      */
      JoinClauseSyntax(NodeId nodeId, Factory *factory);

      /**
      * \internal
      * \brief Non-public destructor, only factory can destroy nodes.
      */
      virtual ~JoinClauseSyntax();

    private:
      /**
      * \brief This function always throws a CsharpException due to copying is not allowed!
      */
      JoinClauseSyntax & operator=(const JoinClauseSyntax&);

      /**
      * \brief This function always throws a CsharpException due to copying is not allowed!
      */
      JoinClauseSyntax(const JoinClauseSyntax&);

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


      // ---------- Attribute getter function(s) ----------

      /**
      * \brief Gives back the identifier of the node.
      * \return Returns with the identifier.
      */
      const std::string& getIdentifier() const;

      /**
      * \brief Gives back the Key of identifier of the node.
      * \return Returns with the Key of the identifier.
      */
      Key getIdentifierKey() const;


      // ---------- Attribute setter function(s) ----------

      /**
      * \internal
      * \brief Sets the identifier of the node.
      * \param identifier [in] The new value of the identifier.
      */
      void setIdentifier(const std::string& _identifier);

      /**
      * \internal
      * \brief Sets the identifier of the node.
      * \param identifier [in] The new Key of the identifier.
      */
      void setIdentifierKey(Key _identifier);

    protected:

      // ---------- Attribute(s) ----------

      /** \internal \brief The Key of the `identifier`. */
      Key m_identifier;

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
      * \brief Gives back the pointer of the node the InExpression edge points to.
      * \return Returns the end point of the InExpression edge.
      */
      expression::ExpressionSyntax* getInExpression() const;

      /**
      * \brief Gives back the pointer of the node the Into edge points to.
      * \return Returns the end point of the Into edge.
      */
      structure::JoinIntoClauseSyntax* getInto() const;

      /**
      * \brief Gives back the pointer of the node the LeftExpression edge points to.
      * \return Returns the end point of the LeftExpression edge.
      */
      expression::ExpressionSyntax* getLeftExpression() const;

      /**
      * \brief Gives back the pointer of the node the RightExpression edge points to.
      * \return Returns the end point of the RightExpression edge.
      */
      expression::ExpressionSyntax* getRightExpression() const;

      /**
      * \brief Gives back the pointer of the node the Type edge points to.
      * \return Returns the end point of the Type edge.
      */
      expression::TypeSyntax* getType() const;


      // ---------- Edge setter function(s) ----------

      /**
      * \brief Sets the InExpression edge.
      * \param id [in] The new end point of the InExpression edge.
      */
      void setInExpression(NodeId id);

      /**
      * \brief Sets the InExpression edge.
      * \param node [in] The new end point of the InExpression edge.
      */
      void setInExpression(expression::ExpressionSyntax *node);

      /**
      * \brief remove the InExpression edge.
      */
      void removeInExpression();

      /**
      * \brief Sets the Into edge.
      * \param id [in] The new end point of the Into edge.
      */
      void setInto(NodeId id);

      /**
      * \brief Sets the Into edge.
      * \param node [in] The new end point of the Into edge.
      */
      void setInto(JoinIntoClauseSyntax *node);

      /**
      * \brief remove the Into edge.
      */
      void removeInto();

      /**
      * \brief Sets the LeftExpression edge.
      * \param id [in] The new end point of the LeftExpression edge.
      */
      void setLeftExpression(NodeId id);

      /**
      * \brief Sets the LeftExpression edge.
      * \param node [in] The new end point of the LeftExpression edge.
      */
      void setLeftExpression(expression::ExpressionSyntax *node);

      /**
      * \brief remove the LeftExpression edge.
      */
      void removeLeftExpression();

      /**
      * \brief Sets the RightExpression edge.
      * \param id [in] The new end point of the RightExpression edge.
      */
      void setRightExpression(NodeId id);

      /**
      * \brief Sets the RightExpression edge.
      * \param node [in] The new end point of the RightExpression edge.
      */
      void setRightExpression(expression::ExpressionSyntax *node);

      /**
      * \brief remove the RightExpression edge.
      */
      void removeRightExpression();

      /**
      * \brief Sets the Type edge.
      * \param id [in] The new end point of the Type edge.
      */
      void setType(NodeId id);

      /**
      * \brief Sets the Type edge.
      * \param node [in] The new end point of the Type edge.
      */
      void setType(expression::TypeSyntax *node);

      /**
      * \brief remove the Type edge.
      */
      void removeType();

    protected:

      // ---------- Edges ----------

      /** \internal \brief The id of the node the InExpression edge points to. */
      NodeId m_InExpression;

      /** \internal \brief The id of the node the Into edge points to. */
      NodeId m_Into;

      /** \internal \brief The id of the node the LeftExpression edge points to. */
      NodeId m_LeftExpression;

      /** \internal \brief The id of the node the RightExpression edge points to. */
      NodeId m_RightExpression;

      /** \internal \brief The id of the node the Type edge points to. */
      NodeId m_Type;

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

