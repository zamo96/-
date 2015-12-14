object Form1: TForm1
  Left = 657
  Top = 239
  Width = 845
  Height = 532
  Caption = 'Directory of radiobroadcasts'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Chart: TChart
    Left = 0
    Top = 211
    Width = 380
    Height = 283
    BackWall.Brush.Color = clWhite
    BackWall.Brush.Style = bsClear
    Title.Text.Strings = (
      'Average volume on each frequency')
    BottomAxis.Title.Caption = 'Frequency'
    LeftAxis.Title.Caption = 'Volume'
    Legend.Visible = False
    View3D = False
    Align = alClient
    TabOrder = 0
    object Series2: TBarSeries
      Marks.ArrowLength = 20
      Marks.Style = smsXValue
      Marks.Visible = False
      SeriesColor = clBlue
      Title = 'SizeGraph'
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Bar'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object ListView: TListView
    Left = 0
    Top = 0
    Width = 829
    Height = 211
    Align = alTop
    Anchors = [akLeft, akTop, akRight, akBottom]
    Columns = <
      item
        AutoSize = True
        Caption = 'Begin'
      end
      item
        AutoSize = True
        Caption = 'End'
      end
      item
        AutoSize = True
        Caption = 'Volume'
      end
      item
        AutoSize = True
        Caption = 'Frequency'
      end
      item
        Caption = 'Name'
      end>
    GridLines = True
    ReadOnly = True
    RowSelect = True
    TabOrder = 1
    ViewStyle = vsReport
    OnClick = ListViewClick
    OnSelectItem = selectItem
  end
  object Panel1: TPanel
    Left = 380
    Top = 211
    Width = 449
    Height = 283
    Align = alRight
    Caption = 'Panel1'
    TabOrder = 2
    Visible = False
    object GroupBox1: TGroupBox
      Left = 1
      Top = 1
      Width = 217
      Height = 372
      Align = alCustom
      Caption = 'Change'
      TabOrder = 0
      Visible = False
      DesignSize = (
        217
        372)
      object Label1: TLabel
        Left = 16
        Top = 24
        Width = 27
        Height = 13
        Caption = 'Begin'
      end
      object Label2: TLabel
        Left = 16
        Top = 56
        Width = 19
        Height = 13
        Caption = 'End'
      end
      object Label3: TLabel
        Left = 16
        Top = 88
        Width = 35
        Height = 13
        Caption = 'Volume'
      end
      object Label4: TLabel
        Left = 16
        Top = 119
        Width = 50
        Height = 13
        Caption = 'Frequency'
      end
      object Label9: TLabel
        Left = 24
        Top = 334
        Width = 137
        Height = 13
        Anchors = [akLeft, akBottom]
        Caption = 'The most loaded frequencies'
      end
      object chNach1: TEdit
        Left = 80
        Top = 24
        Width = 25
        Height = 21
        TabOrder = 0
      end
      object chNach2: TEdit
        Left = 104
        Top = 24
        Width = 25
        Height = 21
        TabOrder = 1
      end
      object editEndHH: TEdit
        Left = 80
        Top = 56
        Width = 25
        Height = 21
        TabOrder = 2
      end
      object editEndMM: TEdit
        Left = 104
        Top = 56
        Width = 25
        Height = 21
        TabOrder = 3
      end
      object editSize: TEdit
        Left = 80
        Top = 88
        Width = 49
        Height = 21
        TabOrder = 4
      end
      object editChastota: TEdit
        Left = 80
        Top = 120
        Width = 49
        Height = 21
        TabOrder = 5
      end
      object change_btn: TButton
        Left = 64
        Top = 191
        Width = 113
        Height = 41
        Anchors = [akLeft, akBottom]
        Caption = 'Change'
        TabOrder = 6
        OnClick = change_btnClick
      end
      object ComboBox2: TComboBox
        Left = 24
        Top = 144
        Width = 89
        Height = 21
        ItemHeight = 13
        TabOrder = 7
        Text = 'ComboBox2'
        Items.Strings = (
          #1087#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
          #1087#1086' '#1091#1073#1099#1074#1072#1085#1080#1102)
      end
      object Button1: TButton
        Left = 134
        Top = 144
        Width = 75
        Height = 25
        Caption = 'Sortirovka'
        TabOrder = 8
        OnClick = Button1Click
      end
      object del_btn: TButton
        Left = 64
        Top = 246
        Width = 313
        Height = 33
        Anchors = [akLeft, akBottom]
        Caption = 'Delete'
        TabOrder = 9
        OnClick = del_btnClick
      end
      object maxChastota: TEdit
        Left = 0
        Top = 350
        Width = 209
        Height = 21
        Anchors = [akLeft, akBottom]
        TabOrder = 10
      end
      object open_btn: TButton
        Left = 64
        Top = 286
        Width = 153
        Height = 49
        Anchors = [akLeft, akBottom]
        Caption = 'Load'
        TabOrder = 11
        OnClick = open_btnClick
      end
    end
    object GroupBox2: TGroupBox
      Left = 222
      Top = 1
      Width = 234
      Height = 372
      Align = alCustom
      Caption = 'Add'
      TabOrder = 1
      Visible = False
      DesignSize = (
        234
        372)
      object Label5: TLabel
        Left = 16
        Top = 24
        Width = 27
        Height = 13
        Caption = 'Begin'
      end
      object Label6: TLabel
        Left = 16
        Top = 56
        Width = 19
        Height = 13
        Caption = 'End'
      end
      object Label7: TLabel
        Left = 16
        Top = 88
        Width = 35
        Height = 13
        Caption = 'Volume'
      end
      object Label8: TLabel
        Left = 16
        Top = 120
        Width = 50
        Height = 13
        Caption = 'Frequency'
      end
      object Label10: TLabel
        Left = 41
        Top = 334
        Width = 137
        Height = 13
        Anchors = [akLeft, akBottom]
        Caption = 'The least loaded frequencies'
      end
      object addNach1: TEdit
        Left = 80
        Top = 24
        Width = 25
        Height = 21
        TabOrder = 0
      end
      object addNach2: TEdit
        Left = 104
        Top = 24
        Width = 25
        Height = 21
        TabOrder = 1
      end
      object addEndHH: TEdit
        Left = 80
        Top = 56
        Width = 25
        Height = 21
        TabOrder = 2
      end
      object addEndMM: TEdit
        Left = 104
        Top = 56
        Width = 25
        Height = 21
        TabOrder = 3
      end
      object addSize: TEdit
        Left = 80
        Top = 88
        Width = 49
        Height = 21
        TabOrder = 4
      end
      object addChastota: TEdit
        Left = 80
        Top = 120
        Width = 49
        Height = 21
        TabOrder = 5
      end
      object Search: TButton
        Left = 128
        Top = 144
        Width = 75
        Height = 25
        Caption = 'Search'
        TabOrder = 6
        OnClick = SearchClick
      end
      object Edit1: TEdit
        Left = 16
        Top = 144
        Width = 121
        Height = 21
        TabOrder = 7
        Text = 'Edit1'
      end
      object add_btn: TButton
        Left = 9
        Top = 195
        Width = 113
        Height = 41
        Anchors = [akLeft, akBottom]
        Caption = 'Add'
        TabOrder = 8
        OnClick = add_btnClick
      end
      object save_btn: TButton
        Left = 17
        Top = 286
        Width = 161
        Height = 49
        Anchors = [akLeft, akBottom]
        Caption = 'Save'
        TabOrder = 9
        OnClick = save_btnClick
      end
      object minChastota: TEdit
        Left = 9
        Top = 350
        Width = 225
        Height = 21
        Anchors = [akLeft, akBottom]
        TabOrder = 10
      end
    end
  end
  object Button2: TButton
    Left = 0
    Top = 208
    Width = 75
    Height = 25
    Caption = 'Load'
    TabOrder = 3
    OnClick = Button2Click
  end
end
