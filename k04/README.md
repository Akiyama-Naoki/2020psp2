# 課題4 レポート

aa83988848 薗田光太郎

## 課題

[../sample/heights.csv]は標本全体（男性と女性合わせた14人）のデータをまとめたものである．
一方，[../sample/IDs.csv]は標本14人の学籍番号（身長データと同じ順番）である．
学籍番号を尋ねて，その学籍番号のデータがリストにあれば，学籍番号，身長，性別のデータを表示し，リストになければ，「No data」と表示せよ．

この二つのファイルを読み取り，学籍番号，身長，性別の3つをメンバーとする構造体の配列で管理するとよい．

## ソースコードの説明
l.47~l.60 ファイル内の性別、身長、IDのデータをgender,heights,IDに代入
l.62 調べるIDの入力
l.69~l.74 性別の判定
l.65~l.81 調べるIDのデータがあれば性別の判定をしID、性別、身長を表示
        　なければnodataをカウント
l.83~l.85 nodataが14（全てのIDのデータと一致しない）ならNO dataと表示

## 入出力結果

例えば，ID 45313125のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313125
---
ID : 45313125
gender : Female
height : 152.4
```
input the filename of sample heights:..\sample\heights.csv
input the filename of sample ID:..\sample\IDs.csv
Whici ID's data do you want?: 45313125
ID :45313125
gender :Female
heights :152.40

例えば，ID 45313124のデータを調べたいとき，

```
Input the filename of sample height : ../sample/heights.csv
Input the filename of sample ID : ../sample/IDs.csv
Which ID's data do you want? : 45313124
---
No data
```
input the filename of sample heights:..\sample\heights.csv
input the filename of sample ID:..\sample\IDs.csv
Whici ID's data do you want?: 45313124
No data

## 修正履歴

[comment #20200611 moto]
- OKです。