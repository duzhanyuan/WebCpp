/*************************************************************************
 * Copyright © 2011-2013 Kévin Lesénéchal <kevin@lesenechal.org>         *
 *                                                                       *
 * This file is part of WebCpp, see <http://www.webcpp.org/>.            *
 *                                                                       *
 * WebCpp is free software: you can redistribute it and/or modify it     *
 * under the terms of the GNU General Public License as published by the *
 * Free Software Foundation, either version 3 of the License, or (at     *
 * your option) any later version.                                       *
 *                                                                       *
 * WebCpp is distributed in the hope that it will be useful, but WITHOUT *
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or *
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License  *
 * for more details.                                                     *
 *                                                                       *
 * You should have received a copy of the GNU General Public License     *
 * along with WebCpp. If not, see <http://www.gnu.org/licenses/>.        *
 *************************************************************************/

/**
 * @file Blocks/InheritanceBlocks.h
 * @author Kévin Lesénéchal <kevin@lesenechal.org>
 * @date 2013-06-12
 */

#ifndef _WPP_BLOCKS_INHERITANCEBLOCKS_H_
#define _WPP_BLOCKS_INHERITANCEBLOCKS_H_

#include "Block.h"

namespace Blocks {

class InheritBlock;

class Inherit : public Block
{
public:
	Inherit();
	Inherit(Block* parent);
	virtual ~Inherit() override;

	virtual Block* newInstance(Block* parent) const override;
	virtual void   setArgument(const String& arg) override;
	virtual void   compiledEvent() override;
	virtual String render(Template* tpl, int, int) override;

	CompiledTpl* base() const;
	Block*       inheritBlock(const String& name) const;

private:
	CompiledTpl* _base;
	Map<String, InheritBlock*> _inheritBlocks;
};

//----------------------------------------------------------------------------//

class InheritBlock : public Block
{
public:
	InheritBlock();
	InheritBlock(Block* parent);

	virtual Block* newInstance(Block* parent) const override;
	virtual void   setArgument(const String& arg) override;
	virtual void   compiledEvent() override;
	virtual String render(Template* tpl, int, int) override;

	String inheritName() const;

private:
	String _inheritName;
};

} // ns Blocks

#endif // !_WPP_BLOCKS_INHERITANCEBLOCKS_H_
