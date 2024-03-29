#include "pch.hpp"

#include "Model/Document/Commands/CDeleteDocumentItem.hpp"
#include "Model/Document/Commands/CInsertDocumentItem.hpp"
#include "Model/Document/Commands/CReplaceDocumentItem.hpp"
#include "Model/Document/Commands/CSetTitle.hpp"
#include "Model/Document/Elements/Images/Image.hpp"
#include "Model/Document/Elements/Text/Paragraph.hpp"

#include "Model/Model.hpp"

// size_t GetCorrectInsertIndex(const Model::Container &items,
//							 const std::optional<size_t> &pos = std::nullopt)
//{
//	bool isEndInsert = !pos.has_value();
//
//	size_t itemIndex = isEndInsert
//						   ? (items.size() != 0)
//								 ? items.size() - 1
//								 : 0
//						   : *pos;
//
//	return itemIndex;
// }

// IParagraphSharedPtr Model::InsertParagraph(const std::string &text,
// 										   std::optional<size_t> position)
// {
// 	const auto index = (position.has_value()) ? *position : m_items.size();
//
// 	auto newParagraph = std::make_shared<Paragraph>(text);
// 	auto newDocumentItem = DocumentItem{newParagraph};
//
// 	m_undoManager.AddAndExecuteEdit(std::make_shared<CInsertDocumentItem<Container>>(m_items, newDocumentItem, index));
//
// 	return newParagraph;
// }
//
// IParagraphSharedPtr Model::ReplaceParagraph(const std::string &newText,
// 											std::optional<size_t> position)
// {
// 	const auto index = GetCorrectInsertIndex(m_items, position);
// 	if (index >= m_items.size())
// 	{
// 		throw std::out_of_range("Failed to replace paragraph's text in Document. Given index is out of range");
// 	}
//
// 	auto oldItem = m_items[index];
// 	if (oldItem.GetParagraph() == nullptr)
// 	{
// 		throw std::invalid_argument("Document doesn't contain paragraph at given index.");
// 	}
//
// 	auto newParagraph = std::make_shared<Paragraph>(newText);
// 	auto newDocumentItem = DocumentItem{newParagraph};
// 	m_undoManager.AddAndExecuteEdit(std::make_shared<CReplaceDocumentItem<Container>>(m_items, oldItem, newDocumentItem, index));
//
// 	return newParagraph;
// }

// IImageSharedPtr Model::InsertImage(const Path &path, size_t width, size_t height,
// 								   std::optional<size_t> position)
// {
// 	auto index = (position.has_value()) ? *position : m_items.size();
//
// 	auto newImage = std::make_shared<Image>(path, width, height);
// 	auto newDocumentItem = DocumentItem{newImage};
//
// 	m_undoManager.AddAndExecuteEdit(std::make_shared<CInsertDocumentItem<Container>>(m_items, newDocumentItem, index));
//
// 	return newImage;
// }
//
// IImageSharedPtr Model::ResizeImage(size_t width, size_t height,
// 								   std::optional<size_t> position)
// {
// 	const auto index = GetCorrectInsertIndex(m_items, position);
// 	if (index >= m_items.size())
// 	{
// 		throw std::out_of_range("Failed to replace image in Document. Given index is out of range");
// 	}
//
// 	auto oldItem = m_items[index];
// 	auto oldImage = m_items[index].GetImage();
// 	if (oldImage == nullptr)
// 	{
// 		throw std::invalid_argument("Document doesn't contain paragraph at given index.");
// 	}
//
// 	auto newImage = std::make_shared<Image>(oldImage->GetPath(), width, height);
// 	auto newDocumentItem = DocumentItem{newImage};
// 	m_undoManager.AddAndExecuteEdit(std::make_shared<CReplaceDocumentItem<Container>>(m_items, oldItem, newDocumentItem, index));
//
// 	return newImage;
// }
//
// size_t Model::GetItemsCount() const
// {
// 	return m_items.size();
// }
//
// const DocumentItem &Model::GetItem(size_t index) const
// {
// 	if (index >= GetItemsCount())
// 	{
// 		throw std::out_of_range("Failed to get item from Model. Given index is out of range");
// 	}
//
// 	return m_items[index];
// }
//
// void Model::DeleteItem(size_t index)
// {
// 	if (index >= m_items.size())
// 	{
// 		throw std::out_of_range("Failed to delete item in Model. Given index is out of range");
// 	}
//
// 	m_undoManager.AddAndExecuteEdit(std::make_shared<CDeleteDocumentItem<Container>>(m_items,
// 																					 GetItem(index),
// 																					 index));
// }
//
// const std::string &Model::GetTitle() const
// {
// 	return m_title;
// }
//
void Model::SetTitle(const std::string &title)
{
	// m_undoManager.AddAndExecuteEdit(std::make_shared<CSetTitle>(m_title, title));
}
//
// bool Model::CanUndo() const
// {
// 	return m_undoManager.CanUndo();
// }
//
// void Model::Undo()
// {
// 	m_undoManager.Undo();
// }
//
// bool Model::CanRedo() const
// {
// 	return m_undoManager.CanRedo();
// }
//
// void Model::Redo()
// {
// 	m_undoManager.Redo();
// }
//
// constexpr auto HTML_EXTENSION = ".html";
//
// std::string MakeImageTag(const IImageSharedPtrConst &image)
// {
// 	auto imageSrc = StdPath(".");
// 	imageSrc /= IMAGES_SAVE_DIR_NAME;
// 	imageSrc /= image->GetName();
// 	imageSrc.replace_extension(image->GetPath().extension());
//
// 	auto imageWidth = std::to_string(image->GetWidth());
// 	auto imageHeight = std::to_string(image->GetHeight());
//
// 	return std::string("<img src=\"") + imageSrc.generic_string() + "\" width=\"" + imageWidth + "\" height=\"" + imageHeight + "\"/>";
// }
//
// namespace html_spec_symb
// {
//
// 	const std::map<char, std::string_view> SPEC_SYMBS_TO_HTML_SYMBS{
// 		{'<', "&lt;"},
// 		{'>', "&gt;"},
// 		{'"', "&Prime;"},
// 		{'\'', "&prime;"},
// 		{'&', "&amp;"}};
//
// 	std::string GetEncodedHtmlString(const std::string &src)
// 	{
// 		std::string res{};
// 		res.reserve(src.size());
//
// 		const auto endIt = SPEC_SYMBS_TO_HTML_SYMBS.end();
// 		for (const auto &ch : src)
// 		{
// 			if (auto it = SPEC_SYMBS_TO_HTML_SYMBS.find(ch);
// 				it != endIt)
// 			{
// 				res += it->second;
// 			}
// 			else
// 			{
// 				res += ch;
// 			}
// 		}
//
// 		return res;
// 	}
//
// }; // namespace html_spec_symb
//
// constexpr auto INDENT_SIZE = 2;
//
// void SaveHead(std::ostream &output, size_t indentIndex, const std::string &title)
// {
// 	output << MakeSpaceIndentString(' ', INDENT_SIZE, ++indentIndex) + "<head>\n"
// 		   << MakeSpaceIndentString(' ', INDENT_SIZE, ++indentIndex) + "<title>" + title + "</title>\n"
// 		   << MakeSpaceIndentString(' ', INDENT_SIZE, --indentIndex) + "</head>\n";
// }
//
// void SaveImage(const IImageSharedPtrConst &imagePtr, std::ostream &output, const StdPath &imagesSavePath)
// {
// 	if (imagePtr != nullptr)
// 	{
// 		imagePtr->Save(imagesSavePath);
// 		output << MakeImageTag(imagePtr);
// 	}
// }
//
// void SaveParagraph(const IParagraphSharedPtrConst &paragraphPtr, std::ostream &output)
// {
// 	if (paragraphPtr != nullptr)
// 	{
// 		using namespace html_spec_symb;
//
// 		output << "<p>" + GetEncodedHtmlString(paragraphPtr->GetText()) + "</p>";
// 	}
// }
//
// constexpr auto DOCTYPE_STR = "<!DOCTYPE html>\n";
//
// class ExceptionsHolder : public std::exception
// {
// public:
// 	ExceptionsHolder() = default;
//
// 	template <typename ExceptionT>
// 	void AddMessage(ExceptionT &&e)
// 	{
// 		m_items.emplace_back(std::forward<ExceptionT>(e));
// 	}
//
// 	const char *what() const noexcept override
// 	{
// 		if (m_msg.empty())
// 		{
// 			for (const auto &e : m_items)
// 			{
// 				m_msg += std::string(e.what()) + '\n';
// 			}
// 		}
//
// 		return m_msg.c_str();
// 	}
//
// 	bool Empty() const
// 	{
// 		return m_items.size() == 0;
// 	}
//
// private:
// 	mutable std::string m_msg;
// 	std::vector<std::exception> m_items;
// };
//
// void FormModel(const std::string &title, const Model::Container &items, std::ostream &output, const StdPath &imagesSavePath)
// {
// 	output << DOCTYPE_STR;
//
// 	size_t indentIndex{};
// 	output << "<html lang=\"en\">\n";
//
// 	SaveHead(output, indentIndex, title);
//
// 	output << MakeSpaceIndentString(' ', INDENT_SIZE, ++indentIndex) + "<body>\n";
//
// 	ExceptionsHolder holder{};
//
// 	++indentIndex;
// 	for (const auto &item : items)
// 	{
// 		auto imagePtr = item.GetImage();
// 		auto paragraphPtr = item.GetParagraph();
//
// 		output << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex);
//
// 		try
// 		{
// 			SaveImage(imagePtr, output, imagesSavePath);
// 		}
// 		catch (std::exception &e)
// 		{
// 			output << "<!--Failed to save '" + imagePtr->GetName() + "' image-->";
// 			holder.AddMessage(e);
// 		}
//
// 		SaveParagraph(paragraphPtr, output);
//
// 		output << std::endl;
// 	}
// 	--indentIndex;
//
// 	output << MakeSpaceIndentString(' ', INDENT_SIZE, indentIndex) + "</body>\n"
// 		   << "</html>" << std::endl;
//
// 	if (!holder.Empty())
// 	{
// 		throw holder;
// 	}
// }
//
// StdPath MakeImagesDirectory(const StdPath &where)
// {
// 	StdPath imagesSavePath = std::filesystem::current_path(), relativeImagesPath = where;
// 	relativeImagesPath /= IMAGES_SAVE_DIR_NAME;
// 	imagesSavePath /= relativeImagesPath;
//
// 	if (!std::filesystem::exists(imagesSavePath))
// 	{
// 		std::filesystem::create_directory(imagesSavePath);
// 	}
//
// 	return imagesSavePath;
// }
//
// std::tuple<std::ofstream, StdPath> CreateHTMLHandler(const StdPath &path, const std::string &fileName)
// {
// 	StdPath correctPath = path;
// 	correctPath /= fileName;
// 	correctPath = correctPath.replace_extension(HTML_EXTENSION);
//
// 	return std::make_tuple(std::ofstream{correctPath.generic_string()}, correctPath);
// }
//
// void Model::Save(const StdPath &path) const
// {
// 	if (!std::filesystem::is_directory(path))
// 	{
// 		std::filesystem::create_directory(path);
// 	}
//
// 	auto [fHandler, savePath] = CreateHTMLHandler(path, m_title);
//
// 	auto imagesDir = (CountImages() != 0)
// 						 ? MakeImagesDirectory(savePath.parent_path())
// 						 : "";
//
// 	FormModel(m_title, m_items, fHandler, imagesDir);
// }
//
// using Iterator = Model::Iterator;
// using ConstIterator = Model::ConstIterator;
//
// Iterator Model::begin()
// {
// 	return std::make_shared<IteratorWrapper<DocumentItem, Container::iterator>>(m_items.begin(), m_items.end());
// }
//
// ConstIterator Model::begin() const
// {
// 	return std::make_shared<IteratorWrapper<const DocumentItem, Container::const_iterator>>(m_items.begin(), m_items.end());
// }
//
// size_t Model::CountImages() const
// {
// 	size_t res{};
// 	for (const auto &item : m_items)
// 	{
// 		if (item.GetImage() != nullptr)
// 		{
// 			++res;
// 		}
// 	}
//
// 	return res;
// }
