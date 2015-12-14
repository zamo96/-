//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include "Unit1.h"
#include "Unit2.h"
#include <stdio.h>

using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
//размер массива
#define SIZE 100
 int pp ; //счетчик элементов массива  поиска
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        //создание нового массива
        connect = new CONNECTION[SIZE];
}

__fastcall TForm1::~TForm1()
{
        //удаление массива (освобождение памяти)
        delete connect;
}
//---------------------------------------------------------------------------
//обновление ListView
void TForm1::sort()
{
AnsiString criterie,uslovie;
 criterie = Form2->ComboBox2->Items->Strings[Form2->ComboBox2->ItemIndex]  ;
 uslovie  = Form2->ComboBox1->Items->Strings[Form2->ComboBox1->ItemIndex]   ;
  if (uslovie == "Begin")
 for(int i = 0; i<connect_count+1;i++)
 {
 for(int j = i;j<connect_count+1;j++)
 {
 if(criterie=="по возрастанию")
 if(connect[i].begin>connect[j].begin)
 swap(connect[i],connect[j]);
 else if(criterie == "по убыванию")
  if(connect[i].begin<connect[j].begin)
 swap(connect[i],connect[j]);
 }
 }
 if (uslovie == "End")
 for(int i = 0; i<connect_count+1;i++)
 {
 for(int j = i;j<connect_count+1;j++)
 {
 if(criterie=="по возрастанию")
 if(connect[i].end>connect[j].end)
 swap(connect[i],connect[j]);
 else if(criterie == "по убыванию")
  if(connect[i].end<connect[j].end)
 swap(connect[i],connect[j]);
 }
 }
 if(uslovie=="Volume")
 for(int i = 0; i<connect_count+1;i++)
 {
 for(int j = i;j<connect_count+1;j++)
 {
 if(criterie=="по возрастанию")
 if(connect[i].size>connect[j].size)
 swap(connect[i],connect[j]);
 else if(criterie == "по убыванию")
  if(connect[i].size<connect[j].size)
 swap(connect[i],connect[j]);
 }
 }
  if(uslovie=="Frequency")
  for(int i = 0; i<connect_count+1;i++)
 {
 for(int j = i;j<connect_count+1;j++)
 {
 if(criterie=="по возрастанию")
 if(connect[i].period>connect[j].period)
 swap(connect[i],connect[j]);
 else if(criterie == "по убыванию")
  if(connect[i].period<connect[j].period)
 swap(connect[i],connect[j]);
 }
 }
 if(uslovie=="Name")
  for(int i = 0; i<connect_count+1;i++)
 {
 for(int j = i;j<connect_count+1;j++)
 {
 if(criterie=="по возрастанию")
 if(connect[i].name>connect[j].name)
 swap(connect[i],connect[j]);
 else if(criterie == "по убыванию")
  if(connect[i].name<connect[j].name)
 swap(connect[i],connect[j]);
 }
 }
updateListView();
}

void TForm1::updateListView()
{
        ListView->Items->BeginUpdate();    //начало обмновления
        ListView->Items->Clear();          //очистка LisView

        for (int i=0; i<connect_count+1; i++)
        {
                //добавление очередного элемента в ListView
                TListItem* item = ListView->Items->Add();
                item->Caption = toTime(connect[i].begin/60)+':'+
                        toTime(connect[i].begin%60);
                item->Data = (void*)i;
                item->SubItems->Add(toTime(connect[i].end/60)+':'+
                        toTime(connect[i].end%60));
                item->SubItems->Add(connect[i].size);
                item->SubItems->Add(connect[i].period);
                item->SubItems->Add(connect[i].name);
        }

        ListView->Items->EndUpdate();          //окончание обновления

        //вычисление наиболее загруженных частот
        Form2->maxChastota->Text = getAllMaxPeriod();
        //вычисление наименее загруженных частот
        Form2->minChastota->Text = getAllMinPeriod();
        //обновление диаграммы
        updateChart();
}
//добавление "0" в часах и минутах с оной цифрой в числе
AnsiString TForm1::toTime(int n)
{
        if (n<10)
        {
                AnsiString str = "0"+IntToStr(n);
                return str;
        }
        else
                return IntToStr(n);
}
//---------------------------------------------------------------------------
//добавление соединения
void __fastcall TForm1::add_btnClick(TObject *Sender)
{
        if(GroupBox2->Visible== false)
        {
         GroupBox2->Visible= true;
         return;
        }
        //проверка, что все поля не пустые
        if (Form2->addChastota->Text=="" || Form2->addSize->Text=="" || Form2->addNach1->Text=="" ||
        Form2->addNach2->Text=="" || Form2->addEndHH->Text=="" || Form2->addEndMM->Text=="")
        {
                ShowMessage("Не все поля заполнены");
                return;
        }

        //Проверка, что время не превышает 24 и 60 соответственно
        if ((Form2->addNach1->Text.ToInt()<0 || Form2->addNach1->Text.ToInt()>=24) ||
        (Form2->addEndHH->Text.ToInt()<0 || Form2->addEndHH->Text.ToInt()>=24) ||
        (Form2->addNach2->Text.ToInt()<0 || Form2->addNach2->Text.ToInt()>=60) ||
        (Form2->addEndMM->Text.ToInt()<0 || Form2->addEndMM->Text.ToInt()>=60))
        {
                ShowMessage("Время введено неверно");
                return;
        }

        //вычисление нового времени в минутах
        int beginNew = Form2->addNach1->Text.ToInt()*60+Form2->addNach2->Text.ToInt();
        int endNew = Form2->addEndHH->Text.ToInt()*60+Form2->addEndMM->Text.ToInt();

        if (beginNew > endNew)
        {
                ShowMessage("Время введено неверно");
                return;
        }

        //добавление нового соединения
        connect_count++;
        connect[connect_count].size = Form2->addSize->Text.ToInt();
        connect[connect_count].period = Form2->addChastota->Text.ToInt();
        connect[connect_count].begin = beginNew;
        connect[connect_count].end = endNew;
        connect[connect_count].name = Form2->Edit3->Text;

        updateListView();    //обновление ListView
}
//---------------------------------------------------------------------------
//выбор соединения
void __fastcall TForm1::selectItem(TObject *Sender, TListItem *Item,
      bool Selected)
{
        int i = (int)Item->Data; //индекс выбранногоэелемнта в массиве

        //заполнение полей для редактирования
        Form2->editSize->Text = connect[i].size;
        Form2->editChastota->Text = connect[i].period;
        Form2->chNach1->Text = connect[i].begin / 60; //часы начала
        Form2->chNach2->Text = connect[i].begin % 60; //минуты начала
        Form2->editEndHH->Text = connect[i].end / 60;     //часы окончания
        Form2->editEndMM->Text = connect[i].end % 60;     //минуты окончания
        Form2->Edit2->Text = connect[i].name; //наименование радио
}

//изменение соединения
void __fastcall TForm1::change_btnClick(TObject *Sender)
{
        TListItem *Item = ListView->Selected;   //получение выбранного элемента

        if(Item == NULL)        // если ничего не было выбрано - уходим
          return;

        int ind = (int)Item->Data; //индекс выбранного элемента в массиве

        //проверка, что все поля заполнены
        if (Form2->editSize->Text=="" || Form2->editChastota->Text==""
        || Form2->chNach1->Text=="" || Form2->chNach2->Text=="" ||
        Form2->editEndHH->Text=="" || Form2->editEndMM->Text=="")
        {
                ShowMessage("Не все поля заполнены");
                return;
        }

        //проверка, что время не превышает 24 и 60 соответственно
        if ((Form2->chNach1->Text.ToInt()<0 || Form2->chNach1->Text.ToInt()>=24) ||
        (Form2->editEndHH->Text.ToInt()<0 || Form2->editEndHH->Text.ToInt()>=24) ||
        (Form2->chNach2->Text.ToInt()<0 || Form2->chNach2->Text.ToInt()>=60) ||
        (Form2->editEndMM->Text.ToInt()<0 || Form2->editEndMM->Text.ToInt()>=60))
        {
                ShowMessage("Время введено неверно");
                return;
        }

        //вычисление нового времени в минутах
        int beginNew = Form2->chNach1->Text.ToInt()*60+Form2->chNach2->Text.ToInt();
        int endNew = Form2->editEndHH->Text.ToInt()*60+Form2->editEndMM->Text.ToInt();

        if (beginNew > endNew)
        {
                ShowMessage("Время введено неверно");
                return;
        }

        //изменение выбранного соедиения в массиве

        connect[ind].size = Form2->editSize->Text.ToInt();
        connect[ind].period = Form2->editChastota->Text.ToInt();
        connect[ind].begin = beginNew;
        connect[ind].end = endNew;
        connect[ind].name = Form2->Edit2->Text;


        updateListView(); //обновление ListView
}
//---------------------------------------------------------------------------
//удаление соединения
void __fastcall TForm1::del_btnClick(TObject *Sender)
{
        TListItem* MyItem;
        MyItem = ListView->Selected;    //выбранное соединение
        int j;

        if (MyItem != NULL)
        {
                j = (int)MyItem->Data;    //индекс в массиве
                //удаление из массива и смещение последующих элементов
                for (int i=j; i<connect_count; i++)
                {
                        connect[i] = connect[i+1];
                }
                connect_count--;
                MyItem->Delete();
        }

        updateListView();  //обновление ListView
}
//---------------------------------------------------------------------------
//сохранение в файл
void __fastcall TForm1::save_btnClick(TObject *Sender)
{
        FILE* file;
        file = fopen("connections.txt","w+");   //открытие файла для записи

        //проверка, что файл существует и его можно открыть
        if (file == NULL)
        {
                ShowMessage("Невозможно открыть connections.txt для записи");
                return;
        }

        //запись элементов массива в файл
        for (int i=0; i<connect_count+1; i++)
        {
                fprintf(file, "%d\n%d\n%d\n%d\n", connect[i].size,
                connect[i].period,connect[i].begin,connect[i].end);
        }

        fclose(file);  //закрытие файла
}
//---------------------------------------------------------------------------
//загрузка данных из файла
void __fastcall TForm1::open_btnClick(TObject *Sender)
{
        //открытие файла для чтения
        FILE* file = fopen("connections.txt","r");

        //проверка, что  файл можено открыть
        if (file == NULL)
        {
                ShowMessage("Невозможно открыть connections.txt для чтения");
                return;
        }

        fclose(file);

        //хагрузка данных из файла в массив строк
        TStringList *list = new TStringList();
        list->LoadFromFile("connections.txt");

        //запись элементов в массив
        for (int i=0; i<list->Count/5; i++)
        {
                connect[i].size = list->Strings[i*5].ToInt();
                connect[i].period = list->Strings[i*5+1].ToInt();
                connect[i].begin = list->Strings[i*5+2].ToInt();
                connect[i].end = list->Strings[i*5+3].ToInt();
                connect[i].name = list->Strings[i*5+4];
        }

        connect_count = list->Count/5-1;

        updateListView();  //обновление ListView
        GroupBox1->Visible= false;
}

//---------------------------------------------------------------------------

//получение значения общей загруженности частоты (n - частота)
int TForm1::getLoadPeriod(int n)
{
        int sum = 0;
        for (int i=0; i<connect_count+1; i++)
        {
                if (connect[i].period == n)
                        sum += connect[i].size;
        }
        return sum;
}
//получение значения максимальной общей загруженности среди всех частот
int TForm1::getMaxLoadPeriod()
{
        int max = 0;
        for (int i=0; i<connect_count+1; i++)
        {
                int load = getLoadPeriod(connect[i].period);
                if (max < load)
                        max = load;
        }
        return max;
}
//получение значения минимальной общей загруженности среди всех частот
int TForm1::getMinLoadPeriod()
{
        int min = getLoadPeriod(connect[0].period);
        for (int i=1; i<connect_count+1; i++)
        {
                int load = getLoadPeriod(connect[i].period);
                if (min > load)
                        min = load;
        }
        return min;
}
//получение всех частот, загруженность которых максимальна
AnsiString TForm1::getAllMaxPeriod()
{
        int max = getMaxLoadPeriod();
        bool first = true;
        AnsiString str = "";

        for (int i=0; i<connect_count+1; i++)
        {
                bool flag = false;
                for(int j=0; j<i; j++)
                        if (connect[i].period == connect[j].period)
                                flag = true;
                if (flag)
                        continue;

                if (getLoadPeriod(connect[i].period) == max)
                        if (first)
                        {
                                first = false;
                                str = str + IntToStr(connect[i].period);
                        }
                        else
                                str = str +", "+ IntToStr(connect[i].period);
        }

        return str;
}
//получение всех частот, загруженность которых минимальна
AnsiString TForm1::getAllMinPeriod()
{
        int min = getMinLoadPeriod();
        bool first = true;
        AnsiString str = "";

        for (int i=0; i<connect_count+1; i++)
        {
                bool flag = false;
                for(int j=0; j<i; j++)
                        if (connect[i].period == connect[j].period)
                                flag = true;
                if (flag)
                        continue;

                if (getLoadPeriod(connect[i].period) == min)
                        if (first)
                        {
                                first = false;
                                str = str + IntToStr(connect[i].period);
                        }
                        else
                                str = str +", "+ IntToStr(connect[i].period);
        }
        return str;
}
//---------------------------------------------------------------------------
//получение среднего объема передаваемых данных для определённой частоты
int TForm1::getAverageLoadPeriod(int n)
{
        int sum = 0;
        int count = 0;

        for(int i=0; i< connect_count+1; i++)
        {
                if (connect[i].period == n)
                {
                        sum += connect[i].size;
                        count++;
                }
        }

        if (count)
                return sum/count;
        else
                return 0;
}
//обновление диаграммы отображающей среднее значение объёма передаваемой
//информации по каждой частоте
void TForm1::updateChart()
{
        Series2->Clear();

        for (int i=0; i<connect_count+1; i++)
        {
                bool flag = false;
                for(int j=0; j<i; j++)
                        if (connect[i].period == connect[j].period)
                                flag = true;
                if (flag)
                        continue;

                Series2->Add(getAverageLoadPeriod(connect[i].period),
                        connect[i].period);
        }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button1Click(TObject *Sender)
{
sort();

}
//---------------------------------------------------------------------------














void __fastcall TForm1::SearchClick(TObject *Sender)
{
                pp = 0;   // начальное значение счетчика для массива поиска
             CONNECTION * search_connect;
             search_connect = new CONNECTION[SIZE];  // создаем массив из 100 элементов структур
        char *stroka = new char[Form2->Edit1->Text.Length()+1]; // массив со строкой
        strcpy(stroka,Form2-> Edit1->Text.c_str());   // копируем строку из текстого поля в массив со строкой
        int length =Form2-> Edit1->Text.Length(); // длина строки

  for(int i = 0;i<connect_count + 1;i++)
  {
  char* c;            // указатель на чар
    c = (char *)malloc(10 * sizeof(char)); // выделяем память под 10 элементов
    int v = 0;     // кол-во цифр в периоде
    int n ;
  n = connect[i].period ;   // в переменную записываем период
  while (n > 9)
    {
        c[v++] = (n % 10) + '0';    // записываем в массив чар по символьно наше число
        n = n / 10;
    }
    c[v++] = n + '0';
    c[v] = '\0';      // в конец обязательно добавляем нуль терминатор)
    char t;      // переменная посредник
    for (int i = 0; i < v / 2; i++)  // цикл для смены порядка в массиве цифр т.е у нас там получилось тип число 956 как [6][5][9] а нам надо [9][5][6]
    {
        t = c[i];    // записываем в нее i ый элемент массива цифр (т.е цифру)
        c[i] = c[v - 1 - i];
        c[v - 1 - i] = t;
    }
    v = 0;   // обнуляем
        if(strncmp(c,stroka,length)==0)
        {
        search_connect[pp] = connect[i];
        pp++;
      }
  }
  searchbuild(search_connect); // заполнение ListView уже массивом search_connect
}
//---------------------------------------------------------------------------
void TForm1:: searchbuild(CONNECTION *p )
{
 ListView->Items->BeginUpdate();    //начало обновления
        ListView->Items->Clear();          //очистка LisView

        for (int i=0; i<pp; i++)
        {
                //добавление очередного элемента в ListView
                TListItem* item = ListView->Items->Add();
                item->Caption = toTime(p[i].begin/60)+':'+
                        toTime(p[i].begin%60);
                item->Data = (void*)i;
                item->SubItems->Add(toTime(p[i].end/60)+':'+
                        toTime(p[i].end%60));
                item->SubItems->Add(p[i].size);
                item->SubItems->Add(p[i].period);
                 item->SubItems->Add(p[i].name);
        }

        ListView->Items->EndUpdate();          //окончание обновления

}

void __fastcall TForm1::Button2Click(TObject *Sender)
{
Form1->open_btn->Click();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListViewClick(TObject *Sender)
{
Form2->Visible = true;
}
//---------------------------------------------------------------------------

