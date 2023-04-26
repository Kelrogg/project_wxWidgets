#ifndef ICONTROLLER_HPP
#define ICONTROLLER_HPP

class IController
{
public:
    // virtual bool ToggleView();
    virtual ~IController() = default;

    // void Redo();
    // void Undo();

    // void DeleteItem();
    // void InsertParagparh();
    // void InsertImage();
    // void ListDocument();
    // void ResizeImage();
    // void ReplaceText();
    // void Save();
    virtual void SetTitle(std::string const &title) = 0;
};

#endif