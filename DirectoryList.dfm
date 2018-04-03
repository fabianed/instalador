object DirList: TDirList
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = 'Seleccione el directorio de instalaci'#243'n'
  ClientHeight = 281
  ClientWidth = 226
  Color = clWhite
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 44
    Top = 217
    Width = 172
    Height = 13
    Caption = 'C:\...\Embarcadero\Studio\19.0\bin'
  end
  object DirectoryListBox1: TDirectoryListBox
    Left = 3
    Top = 23
    Width = 220
    Height = 210
    DirLabel = Label1
    TabOrder = 0
    StyleElements = []
  end
  object BAceptar: TButton
    Left = 68
    Top = 244
    Width = 89
    Height = 29
    Caption = 'Aceptar'
    TabOrder = 1
    OnClick = BAceptarClick
  end
  object DriveComboBox1: TDriveComboBox
    Left = 3
    Top = 5
    Width = 220
    Height = 19
    DirList = DirectoryListBox1
    TabOrder = 2
  end
end
