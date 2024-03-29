#include "pch.hpp"

#include "Model/Document/Commands/CSetTitle.hpp"

bool CSetTitle::DerivedExecute()
{
	m_target.swap(m_state);

	return true;
}

bool CSetTitle::DerivedUndo()
{
	return DerivedExecute();
}

bool CSetTitle::DerivedRedo()
{
	return DerivedExecute();
}
