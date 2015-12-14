object Form2: TForm2
  Left = 192
  Top = 257
  Width = 466
  Height = 374
  Caption = 'Form2'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  DesignSize = (
    450
    336)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 0
    Top = 0
    Width = 211
    Height = 336
    Align = alLeft
    Caption = 'Change'
    TabOrder = 0
    DesignSize = (
      211
      336)
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
      Top = 298
      Width = 137
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'The most loaded frequencies'
    end
    object Label11: TLabel
      Left = 16
      Top = 144
      Width = 28
      Height = 13
      Caption = 'Name'
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
      Left = 8
      Top = 219
      Width = 113
      Height = 41
      Anchors = [akLeft, akBottom]
      Caption = 'Change'
      TabOrder = 6
      OnClick = change_btnClick
    end
    object ComboBox2: TComboBox
      Left = 72
      Top = 176
      Width = 81
      Height = 21
      ItemHeight = 13
      TabOrder = 7
      Text = #1050#1088#1080#1090#1077#1088#1080#1081
      Items.Strings = (
        #1087#1086' '#1074#1086#1079#1088#1072#1089#1090#1072#1085#1080#1102
        #1087#1086' '#1091#1073#1099#1074#1072#1085#1080#1102)
    end
    object Button1: TButton
      Left = 160
      Top = 176
      Width = 41
      Height = 17
      Caption = 'Sort'
      TabOrder = 8
      OnClick = Button1Click
    end
    object maxChastota: TEdit
      Left = 0
      Top = 315
      Width = 209
      Height = 21
      Anchors = [akLeft, akBottom]
      TabOrder = 9
    end
    object Edit2: TEdit
      Left = 80
      Top = 144
      Width = 49
      Height = 21
      TabOrder = 10
    end
    object ComboBox1: TComboBox
      Left = 0
      Top = 176
      Width = 73
      Height = 21
      ItemHeight = 13
      TabOrder = 11
      Text = #1059#1089#1083#1086#1074#1080#1077
      Items.Strings = (
        'Begin'
        'End'
        'Volume'
        'Frequency'
        'Name')
    end
  end
  object GroupBox2: TGroupBox
    Left = 211
    Top = 0
    Width = 239
    Height = 336
    Align = alClient
    Anchors = [akRight]
    Caption = 'Add'
    TabOrder = 1
    DesignSize = (
      239
      336)
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
      Top = 298
      Width = 137
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'The least loaded frequencies'
    end
    object Label12: TLabel
      Left = 16
      Top = 144
      Width = 28
      Height = 13
      Caption = 'Name'
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
      Top = 184
      Width = 75
      Height = 25
      Caption = 'Search'
      TabOrder = 6
      OnClick = SearchClick
    end
    object Edit1: TEdit
      Left = 8
      Top = 176
      Width = 121
      Height = 21
      TabOrder = 7
      Text = #1042#1074#1077#1076#1080#1090#1077' '#1095#1072#1089#1090#1086#1090#1091
    end
    object add_btn: TButton
      Left = 94
      Top = 219
      Width = 113
      Height = 41
      Anchors = [akLeft, akBottom]
      Caption = 'Add'
      TabOrder = 8
      OnClick = add_btnClick
    end
    object minChastota: TEdit
      Left = 0
      Top = 315
      Width = 239
      Height = 21
      Anchors = [akLeft, akBottom]
      TabOrder = 9
    end
    object Edit3: TEdit
      Left = 80
      Top = 144
      Width = 49
      Height = 21
      TabOrder = 10
    end
  end
  object open_btn: TButton
    Left = 130
    Top = 230
    Width = 135
    Height = 35
    Anchors = [akLeft, akBottom]
    Caption = 'Load'
    TabOrder = 2
    OnClick = open_btnClick
  end
  object save_btn: TButton
    Left = 130
    Top = 262
    Width = 135
    Height = 35
    Anchors = [akLeft, akBottom]
    Caption = 'Save'
    TabOrder = 3
    OnClick = save_btnClick
  end
  object PopupMenu1: TPopupMenu
    Left = 144
  end
end
