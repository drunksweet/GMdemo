#pragma once
#include "basicButton.h"

class QuitGameButton : public Button
{
public:
    QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
    ~QuitGameButton();
protected:
    void OnClick();

};


class StartGameButton : public Button
{
public:StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed);
      ~StartGameButton() ;
protected:
    void OnClick();
};
