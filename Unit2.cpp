//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button1Click(TObject *Sender)
{
Form1->Button1->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::Button3Click(TObject *Sender)
{
Form1->Search->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::change_btnClick(TObject *Sender)
{
Form1->change_btn->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::add_btnClick(TObject *Sender)
{
Form1->add_btn->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::SearchClick(TObject *Sender)
{
Form1->Search->Click();
}
//---------------------------------------------------------------------------


void __fastcall TForm2::open_btnClick(TObject *Sender)
{
Form1->open_btn->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::save_btnClick(TObject *Sender)
{
Form1->save_btn->Click();
}
//---------------------------------------------------------------------------



