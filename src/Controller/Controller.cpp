#include "pch.hpp"

#include "Controller/Controller.hpp"

// virtual bool Controller::ToggleView();
//
// void Controller::Redo();
// void Controller::Undo();
//
// void Controller::DeleteItem();
// void Controller::InsertParagparh();
// void Controller::InsertImage();
// void Controller::ListDocument();
// void Controller::ResizeImage();
// void Controller::ReplaceText();
// void Controller::Save();
// void Controller::SetTitle();
//
// virtual void Controller::CreateFrame();
// virtual void Controller::CreateBinds();

/* #include "pch.hpp"

#include "Model/Document/Commands/common.hpp"
#include "Controller/Controller.hpp"

using namespace document_commands;

    namespace descriptions
    {

        constexpr auto DELETE_CMND_DSCRP = "Deletes item at certain <pos>. Args: {pos}";
        constexpr auto EXIT_CMND_DSCRP = "Stops editing document";
        constexpr auto HELP_CMND_DSCRP = "Shows list of available commands";
        constexpr auto INSERT_IMAGE_CMND_DSCRP = "Inserts an image at <path> before <pos> with <width> and <height>. Args: {end|<pos>} <width> <height> <path>";
        constexpr auto INSERT_PARAGRAPH_CMND_DSCRP = "Inserts a paragraph before <pos>. Args: {end|<pos>} <text>";
        constexpr auto LIST_CMND_DSCRP = "Lists document's content";
        constexpr auto REDO_CMND_DSCRP = "Redo undone action";
        constexpr auto RENAME_CMND_DSCRP = "Changes title. Args: <new-title>";
        constexpr auto REPLACE_TEXT_CMND_DSCRP = "Replaces text item at <pos> with new content. Args: {end|<pos>}, <text>";
        constexpr auto RESIZE_IMAGE_CMND_DSCRP = "Resizes image item at <pos> with given <width> and <height>. Args: {end|<pos>} <width> <height>";
        constexpr auto SAVE_CMND_DSCRP = "Saves document. Args: <path>";
        constexpr auto UNDO_CMND_DSCRP = "Undo previous action";

    };


Controller::Controller(IDocumentPtr &&document)
    : m_document(std::move(document))
{
}
//	, m_menu(inputS, outputS)
// m_outputEcho(outputS)
//{
//	using namespace Controller_commands;
//	using namespace descriptions;
//
//	m_menu.AddItem(DELETE_CMND, DELETE_CMND_DSCRP, [this](std::istream& is) {
//		DeleteItem(is);
//	});
//	m_menu.AddItem(EXIT_CMND, EXIT_CMND_DSCRP, [&menu = m_menu](std::istream&) {
//		menu.Exit();
//	});
//	m_menu.AddItem(HELP_CMND, HELP_CMND_DSCRP, [&menu = m_menu](std::istream&) {
//		menu.ShowInstructions();
//	});
//	m_menu.AddItem(LIST_CMND, LIST_CMND_DSCRP, [this](std::istream& is) {
//		ListDocument();
//	});
//	m_menu.AddItem(REDO_CMND, REDO_CMND_DSCRP, [this](std::istream&) {
//		Redo();
//	});
//	m_menu.AddItem(INSERT_PARAGRAPH_CMND, INSERT_PARAGRAPH_CMND_DSCRP, [this](std::istream& is) {
//		InsertParagparh(is);
//	});
//	m_menu.AddItem(REPLACE_TEXT_CMND, REPLACE_TEXT_CMND_DSCRP, [this](std::istream& is) {
//		ReplaceText(is);
//	});
//	m_menu.AddItem(INSERT_IMAGE_CMND, INSERT_IMAGE_CMND_DSCRP, [this](std::istream& is) {
//		InsertImage(is);
//	});
//	m_menu.AddItem(RESIZE_IMAGE_CMND, RESIZE_IMAGE_CMND_DSCRP, [this](std::istream& is) {
//		ResizeImage(is);
//	});
//	m_menu.AddItem(RENAME_CMND, RENAME_CMND_DSCRP, [this](std::istream& is) {
//		SetTitle(is);
//	});
//	m_menu.AddItem(SAVE_CMND, SAVE_CMND_DSCRP, [this](std::istream& is) {
//		Save(is);
//	});
//	m_menu.AddItem(UNDO_CMND, UNDO_CMND_DSCRP, [this](std::istream&) {
//		Undo();
//	});
// }

constexpr auto BAD_STREAM_MSG = "Failed to read arguments. Nothing to read or input stream is bad\n";
constexpr auto BAD_ARGUMENTS_MSG = "Failed to read command's arguments. See help\n";

size_t GetCorrectIndexOfDocumentItem(size_t totalItemsInDocument, const std::string &userInput)
{
    bool isEndInsert = (IEqualStrings(userInput, Controller_commands::INSERT_END_ARG));

    size_t itemIndex = isEndInsert
                           ? totalItemsInDocument
                           : std::stoi(userInput);

    if (totalItemsInDocument != 0 && !isEndInsert)
    {
        --itemIndex;
    }

    return itemIndex;
}

void Controller::DeleteItem(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    std::string index{};
    if (!(is >> index))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    try
    {
        auto deleteIndex = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), index);
        m_document->DeleteItem(deleteIndex);
    }
    catch (const std::exception &e)
    {
        // m_outputEcho << e.what() << std::endl;
    }
}

// void Controller::Start()
//{
//	m_menu.Run();
// }

void Controller::Redo()
{
    if (!m_document->CanRedo())
    {
        // m_outputEcho << "Can't redo\n";
        return;
    }

    m_document->Redo();
}

void Controller::Undo()
{
    if (!m_document->CanUndo())
    {
        // m_outputEcho << "Can't undo\n";
        return;
    }

    m_document->Undo();
}

void Controller::InsertParagparh(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    std::string text{}, paragraphIndex{};
    if (!(is >> paragraphIndex) || !std::getline(is, text))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    trim(text);

    try
    {
        auto insertIndex = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), paragraphIndex);
        m_document->InsertParagraph(text, insertIndex);
    }
    catch (std::exception &exception)
    {
        // m_outputEcho << exception.what() << std::endl;
    }
}

void Controller::InsertImage(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    size_t width{}, height{};
    std::string path{}, imageIndex{};
    if (!(is >> imageIndex) || !(is >> width) || !(is >> height) || !std::getline(is, path))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    trim(path);

    try
    {
        auto insertIndex = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), imageIndex);
        m_document->InsertImage(path, width, height, insertIndex);
    }
    catch (std::exception &exception)
    {
        // m_outputEcho << exception.what() << std::endl;
    }
}

void Controller::ResizeImage(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    std::string imageIndex{};
    size_t width{}, height{};
    if (!(is >> imageIndex) || !(is >> width) || !(is >> height))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    try
    {
        auto index = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), imageIndex);
        m_document->ResizeImage(width, height, index);
    }
    catch (std::exception &exception)
    {
        // m_outputEcho << exception.what() << std::endl;
    }
}

void Controller::ReplaceText(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    std::string text{}, paragraphIndex{};
    if (!(is >> paragraphIndex) || !std::getline(is, text))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    trim(text);

    try
    {
        auto index = GetCorrectIndexOfDocumentItem(m_document->GetItemsCount(), paragraphIndex);
        m_document->ReplaceParagraph(text, index);
    }
    catch (std::exception &exception)
    {
        // m_outputEcho << exception.what() << std::endl;
    }
}

std::string GetDetailInfoAboutDocumentItem(const DocumentItem &item)
{
    using namespace document_item_types;

    bool isImage = item.GetImage() != nullptr;
    bool isParagraph = item.GetParagraph() != nullptr;

    std::string res{};
    if (isImage)
    {
        auto ptr = item.GetImage();

        res += std::string(IMAGE_TYPE_STR) + ": " + std::to_string(ptr->GetWidth()) + " " + std::to_string(ptr->GetHeight()) + " " + ptr->GetPath().generic_string();
    }
    else if (isParagraph)
    {
        auto ptr = item.GetParagraph();

        res = std::string(PARAGRAPH_TYPE_STR) + ": " + ptr->GetText();
    }

    return res;
}

void Controller::ListDocument()
{
    // m_outputEcho << "Title: " << m_document->GetTitle() << '\n';

    auto it = m_document->begin();
    size_t itemIndex = 1;
    while (it->HasNext())
    {
        // m_outputEcho << itemIndex++ << ". " << GetDetailInfoAboutDocumentItem(it->Get()) << '\n';
        it->Next();
    }
}

void Controller::Save(std::istream &is)
{
    if (!std::istream::sentry(is))
    {
        // m_outputEcho << BAD_STREAM_MSG;
        return;
    }

    std::string path;
    if (!std::getline(is, path))
    {
        // m_outputEcho << BAD_ARGUMENTS_MSG;
        return;
    }

    trim(path);

    try
    {
        m_document->Save(path);
    }
    catch (const std::exception &e)
    {
        // m_outputEcho << e.what() << std::endl;
    }
}
*/

void Controller::SetTitle(std::string const &title)
{
    try
    {
        m_model.SetTitle(title);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}