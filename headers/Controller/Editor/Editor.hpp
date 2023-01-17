#ifndef COMMAND_EDITOR_EDITOR_HPP
#define COMMAND_EDITOR_EDITOR_HPP

#include "Document/Model.hpp"

class Editor
{
public:
	Editor(IDocumentPtr &&document);

	void Start();

protected:
	void Redo();
	void Undo();

	void DeleteItem(std::istream &is);
	void InsertParagparh(std::istream &is);
	void InsertImage(std::istream &is);
	void ListDocument();
	void RsizeImage(std::istream &is);
	void ReplaceText(std::istream &is);
	void Save(std::istream &is);
	void SetTitle(std::istream &is);

private:
	IDocumentPtr m_document;
};

#endif
