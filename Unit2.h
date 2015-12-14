//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label9;
        TEdit *chNach1;
        TEdit *chNach2;
        TEdit *editEndHH;
        TEdit *editEndMM;
        TEdit *editSize;
        TEdit *editChastota;
        TButton *change_btn;
        TComboBox *ComboBox2;
        TGroupBox *GroupBox2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label10;
        TEdit *addNach1;
        TEdit *addNach2;
        TEdit *addEndHH;
        TEdit *addEndMM;
        TEdit *addSize;
        TEdit *addChastota;
        TButton *Search;
        TEdit *Edit1;
        TButton *Button1;
        TButton *add_btn;
        TButton *open_btn;
        TButton *save_btn;
        TEdit *maxChastota;
        TEdit *minChastota;
        TEdit *Edit2;
        TPopupMenu *PopupMenu1;
        TComboBox *ComboBox1;
        TLabel *Label11;
        TLabel *Label12;
        TEdit *Edit3;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall change_btnClick(TObject *Sender);
        void __fastcall add_btnClick(TObject *Sender);
        void __fastcall SearchClick(TObject *Sender);
        void __fastcall open_btnClick(TObject *Sender);
        void __fastcall save_btnClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
