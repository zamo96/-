//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
//---------------------------------------------------------------------------
typedef struct
{
        int begin;   //время начала соединения (в минутах)
        int end;     //время окончания сединения (в минутах)
        int size;    //объём переданных данных
        int period;  //частота соединения
        AnsiString name;//название радиопередачи
} CONNECTION;
 CONNECTION* connect;
int connect_count = -1;
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TChart *Chart;
        TBarSeries *Series2;
        TListView *ListView;
        TLabel *Label9;
        TLabel *Label10;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *chNach1;
        TEdit *chNach2;
        TEdit *editEndHH;
        TEdit *editEndMM;
        TEdit *editSize;
        TEdit *editChastota;
        TButton *change_btn;
        TGroupBox *GroupBox2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *addNach1;
        TEdit *addNach2;
        TEdit *addEndHH;
        TEdit *addEndMM;
        TEdit *addSize;
        TEdit *addChastota;
        TButton *add_btn;
        TButton *open_btn;
        TButton *save_btn;
        TEdit *maxChastota;
        TEdit *minChastota;
        TButton *del_btn;
        TButton *Button1;
        TPanel *Panel1;
        TButton *Search;
        TComboBox *ComboBox2;
        TEdit *Edit1;
        TButton *Button2;
        void __fastcall add_btnClick(TObject *Sender);
        void __fastcall selectItem(TObject *Sender, TListItem *Item,
          bool Selected);
        void __fastcall change_btnClick(TObject *Sender);
        void __fastcall del_btnClick(TObject *Sender);
        void __fastcall save_btnClick(TObject *Sender);
        void __fastcall open_btnClick(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall SearchClick(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall ListViewClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        __fastcall ~TForm1();
        void updateListView();
        AnsiString toTime(int n);
        int getLoadPeriod(int n);
        int getMaxLoadPeriod();
        int getMinLoadPeriod();
        AnsiString getAllMaxPeriod();
        AnsiString getAllMinPeriod();
        int getAverageLoadPeriod(int n);
        void updateChart();
        void sort();
        void searchbuild(CONNECTION * p);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
