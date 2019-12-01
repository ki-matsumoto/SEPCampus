# PC環境構築

<div style="text-align: right;">
2019年10月25日<br>
株式会社アルファオメガ  松本清明
</div>

## はじめに
今回のSEPキャンプで使用するソフトウェアのインストールやユーザー作成の設定を行ってください。
これ以外でも必要とするソフトはあるかと思いますが、別の授業でインストールをしているかもしれないので省略致します。


## インターネットブラウザ
Windowsパソコンを使用していると標準でインストールされている Microsoft Internet エクスプローラーや又は Microsoft Edgeを使用している方は多いと思います。インターネットエクスプローラーは開発や終了していますし、新しいパソコンを設定した場合などでメインでインターネットエクスプローラー11を使用するのは避けましょう。

ある程度は好みで問題ないと思いますが、[Google Chrome ウェブブラウザ](https://www.google.com/intl/ja_jp/chrome/) をお勧めします。

<img src="./img/Chrome01.png">

Chromeはプログラマに便利な開発に必要な機能も豊富でとても便利です。
マルチプラットフォームデバイスで開発人たちはWindows環境で iOS/Androidの端末にエミュレータして画面の確認をすることもできます。

## GitHub
[GitHub](https://github.co.jp/)は Gitのリポジトリを利用できる有名なサービスです。作成したプログラムを世界中に公開するのに便利なことや複数のプログラマと共同で作業する場合にとても便利なサイトとなっています。Gitを使用するのに必ずしもGitHubが必要ではありませんが、プロ黒グラムを共有や公開するのに便利な仕組みとなっていますので利用しましょう。
今回の授業で作成したプログラムはGitHub(Git)にコミットしてもらいプログラムを確認させてもらいます。
<img src="./img/GitHub01.png">

### GitHubのアカウント登録
<img src="./img/GitHub02.png">

* username, EMail address, Passwordを決める。
* Verify accountで馬を回してまっすぐにする。
* Create an acountボタンを押してください。

### Freeプランの選択
<img src="./img/GitHub03.png">
デフォルトで Continueボタンを押す。


### 簡単な質問に答える

以下の２つの質問に答える。

What is your level of programming experience? ->
あなたのプログラミング経験はどの程度ですか？

What do you plan to use GitHub for? (Select up to 3) ->
GitHubの使用目的は何ですか？ （3つまで選択）

<img src="./img/GitHub04.png">

答えたら Submitボタンを押す。

### Eメールを送った画面

<img src="./img/GitHub05.png">

### 届いたEメール
<img src="./img/GitHub06.png">

### メールからのリダイレクト
<img src="./img/GitHub07.png">

### e-メールに届いたデバイス検証コード
<img src="./img/GitHub09.png">

### デバイス検証コード入力
<img src="./img/GitHub08.png">

### リポジトリを作成
<img src="./img/GitHub10.png">

### リポジトリを作成完成
<img src="./img/GitHub11.png">

[松本専用のSEPキャンパス・リポジトリができました](https://github.com/matsuo-chan/sep_campus)

## SourceTree

Gitクライアントソフトで有名な[SourceTree](https://www.sourcetreeapp.com/)をインストールします。

<img src="./img/SourceTree01.png">

### ダウンロードの注意
ライセンスに同意出来ればチェックをつけて Downloadボタンを押します。
<img src="./img/SourceTree02.png">

### ダウンロードしたファイルでインストールする
SourceTreeSetup-3.2.6.exeがダウンロードできましたのでこちらからインストールします。

[Gitクライアント! SourceTree の使い方 ～GUIでGitを使おう～ | バージョン管理システム入門(初心者向け)](https://tracpath.com/bootcamp/learning_git_sourcetree.html)のページがインストール手順としてわかりやすかったのでユーザー作成辺りまで参考にして進めてみてください。

## WinMerge
WinMergeはファイルの差分を視覚的に確認するツールです。ソースコードの変更点などを確認するのにとても便利なので[WinMergeのサイト](https://winmerge.org/)からダウンロードして使用してみてください。
<img src="./img/WinMerge01.png">

### SourctTreeとの連携
SourctTree のメニュー[ツール]-[オプション]でオプションダイアログを開いてDiffのページを開くとWinMergeに変更する項目があります。WinMergeをインストールした場合は変更すると便利なので使用してみて下さい。

<img src="./img/WinMerge02_ex.png">


## Visual Stdio Community 2019

[以下のページから](https://docs.microsoft.com/ja-jp/visualstudio/install/install-visual-studio?view=vs-2019) Visual Stduio Community 2019のインストール手順通りに作業して下さい。
<img src="./img/VS2019Install01.png">

以下の画面でCommunityを選択してください。
<img src="./img/VS2019Install02.png">


## Unity Hub と Unity2019

UnityHubとはUnity様々なバージョンのインストールを管理するのに便利なツールです。Unityは頻繁にバージョンアップされていくので、バージョンを管理する意味でも[Unity をダウンロード](https://unity3d.com/jp/get-unity/download)からUnityHubをインストールしてUnityのインストール／アンインストールの管理をするのをお勧めします。

<img src="./img/Unity2019_01.png">
