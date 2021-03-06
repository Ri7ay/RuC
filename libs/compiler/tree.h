/*
 *	Copyright 2020 Andrey Terekhov, Victor Y. Fadeev, Dmitrii Davladov
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 */

#pragma once

#include "syntax.h"
#include <limits.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif

/** Tree type */
typedef int tree;

/** Tree node */
typedef struct node
{
	tree *tree;				/**< Reference to tree */
	size_t type;			/**< Node type */

	size_t argv;			/**< Reference to arguments */
	size_t argc;			/**< Number of arguments */

	size_t children;		/**< Reference to children */
	size_t amount;			/**< Amount of children */
} node;


/**
 *	Get tree root node
 *
 *	@param	sx		Syntax structure
 *
 *	@return	Root node
 */
node node_get_root(syntax *const sx);

/**
 *	Get child from node by index
 *
 *	@param	nd		Parrent node
 *	@param	index	Child number
 *
 *	@return	Child node
 */
node node_get_child(node *const nd, const size_t index);


/**
 *	Get amount of children
 *
 *	@param	nd		Node structure
 *
 *	@return	Amount of children
 */
size_t node_get_amount(const node *const nd);

/**
 *	Get type of node
 *
 *	@param	nd		Node structure
 *
 *	@return	Node type, @c INT_MAX on failure
 */
int node_get_type(const node *const nd);

/**
 *	Get argument from node by index
 *
 *	@param	nd		Node structure
 *	@param	index	Argument number
 *
 *	@return	Argument, @c INT_MAX on failure
 */
int node_get_arg(const node *const nd, const size_t index);


/**
 *	Check that node is correct
 *
 *	@param	nd		Node structure
 *
 *	@return	@c 1 on true, @c 0 on false
 */
int node_is_correct(const node *const nd);


/**
 *	Test tree building
 *
 *	@param	sx	Syntax structure
 *
 *	@return	@c 0 on success, @c -1 on failure
 */
int tree_test(syntax *const sx);

#ifdef __cplusplus
} /* extern "C" */
#endif
