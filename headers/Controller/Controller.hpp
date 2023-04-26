#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Controller/IController.hpp"
#include "Model/Model.hpp"

class Controller : public IController
{
public:
    Controller(Model &&model) : m_model(std::forward<Model>(model))
    {
    }

    // virtual bool ToggleView() override;

    // void Redo() override;
    // void Undo() override;

    // void DeleteItem() override;
    // void InsertParagparh() override;
    // void InsertImage() override;
    // void ListDocument() override;
    // void ResizeImage() override;
    // void ReplaceText() override;
    // void Save() override;
    void SetTitle(std::string const &title) override;

private:
    // wxFrame *frame;
    Model m_model;
    // virtual void CreateFrame();
    // virtual void CreateBinds();
};

#endif