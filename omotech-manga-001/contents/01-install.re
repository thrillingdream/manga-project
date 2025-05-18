= クラウド

//abstract{
第1章では「クラウドサービス」を題材にしています。。普段から使い慣れている人にとっては当たり前のものですが、まだ触れたことのない人には未知の世界かもしれません。

今回の解説では、各社が提供しているコンピューティングやストレージなどの具体的なサービス内容には深入りせず、実際のPCを活用する場合と比較した際の差分を中心に説明していきます。
//}

#@#//makechaptitlepage[toc=on]


== あらすじ

新入社員としてIT企業に就職したりんねは、社内で偶然見かけた小さな女の子（=課長）の所属する4課に配属される。
課長は、AIの開発環境の構築を依頼されており、どうやら自分でPCを組み立てて実現をするらしい。
しかし、PCを組み立て終わる際に、PCの電力供給が大きすぎることが原因で、発火してしまい、偶然近くにあったガスボンベが爆発してしまう。
りんねは、死んでしまうが、天界で神さまにであい、クラウドサービスの知識を授けられ生き返ることに成功する。
りんねは、課長にクラウドサービスのことを伝えて、無事開発環境の構築を成功させた。

== 今回の学び

//talklist{
//talk[avatar-b][][計算リソースを柔軟に調達できるのがクラウドサービスの強みね！]
//talk[avatar-g][][なるほど、クラウドクラウドってみんな言ってたけど、こういうことだったんだ。]
//talk[avatar-b][][計算リソースだけじゃなく、各社いろんな機能を持ったサービスを提供してるから、興味があったらしらべてみてもいいわね。]
//talk[avatar-g][][わかりました！]
//}

== クラウドの定義

NIST（National Institute of Standards and Technology）では、クラウドコンピューティングを次のように定義しています。

//table[][NISTによるクラウドの5つの定義]{
Name Val1
--------------------
オンデマンド・セルフサービス@<br>{}(On-demand self-service) ユーザは、各サービスの提供者と直接やりとりすることなく、必要に応じ、自動的に、サーバーの稼働時間やネットワークストレージのようなコンピューティング能力を一方的に設定できる。
//}

== RubyとTeXLiveのインストール

Re:VIEW StarterでPDFを生成するには、RubyとTeXLiveのインストールが必要です。

 * Rubyとは世界中で人気のあるプログラミング言語のことです。
   原稿ファイル（「@<file>{*.re}」ファイル）を読み込むのに必要です。
 * TeXLiveとは有名な組版ソフトのひとつです。
   PDFファイルを生成するのに必要です。

これらのインストール手順を説明します。


=== Dockerの使い方を知っている場合

Dockerとは、簡単に言えば「WindowsやMacでLinuxコマンドを実行するためのソフトウェア」です@<fn>{guoes}。
//footnote[guoes][Dockerについてのこの説明は、技術的にはちっとも正確ではありません。しかしITエンジニア以外に説明するには、このような説明で充分です。]

Dockerの使い方が分かる人は、@<href>{https://hub.docker.com/r/kauplan/review2.5/, kauplan/review2.5}のDockerイメージを使ってください。
これでRubyとTeXLiveの両方が使えるようになります。

//terminal[][Dockerイメージのダウンロードと動作確認]{
$ @<userinput>{docker pull kauplan/review2.5}   @<balloon>{3GB 以上ダウンロードするので注意}
$ @<userinput>{docker run --rm kauplan/review2.5 ruby --version}
ruby 2.5.1p57 (2018-03-29 revision 63029) [x86_64-linux-gnu]
$ @<userinput>{docker run --rm kauplan/review2.5 uplatex --version}
e-upTeX 3.14159265-p3.7.1-u1.22-161114-2.6 (utf8.uptex) (TeX Live 2017/Debian)
...(省略)...
//}

#@#なおmacOSのようにRubyが使える環境なら、「@<code>|docker pull kauplan/review2.5|」のかわりに「@<code>|rake setup:dockerimage|」を実行してもいいです（内部で同じことを行います）。
なおmacOSのようにRubyが使える環境なら、「@<code>|rake setup:dockerimage|」を実行すると自動的に「@<code>|docker pull kauplan/review2.5|」が実行されます。


=== macOSを使っている場合

macOSにおいて、RubyとTeXLiveをインストールする方法を説明します。

==== Rubyのインストール

macOSには最初からRubyがインストールされているため、Rubyを別途インストールする必要はありません。

Rubyがインストールされていることを確認するために、Terminal.app@<fn>{zp54n}を起動して以下のコマンドを入力してみましょう。
なお各行の先頭にある「@<code>{$ }」は入力せず、下線がついている部分のコマンドを入力してください。
//footnote[zp54n][Terminal.appは、ファインダで「アプリケーション」フォルダ > 「ユーティリティ」フォルダ > 「ターミナル」をダブルクリックすると起動できます。]

//terminal[][Rubyがインストールされていることを確認]{
$ @<userinput>{which ruby}     @<balloon>{下線が引かれたコマンドだけを入力すること}
/usr/bin/ruby    @<balloon>{このような表示になるはず}
$ @<userinput>{ruby --version} @<balloon>{下線が引かれたコマンドだけを入力すること}
ruby 2.3.7p456 (2018-03-28 revision 63024) [universal.x86_64-darwin18]
//}

実際の出力結果は上と少し違うはずですが、だいたい合っていればOKです。

また必要なライブラリをインストールするために、以下のコマンドも実行してください（各行の先頭にある「@<code>{$ }」は入力せず、それ以降のコマンドを入力してください）。

//terminal[][必要なライブラリをインストール]{
### Rubyに詳しくない初心者向け
$ @<userinput>{rake setup:rubygems}

### Rubyに詳しい人向け
$ @<userinput>{gem install review --version=2.5}
$ @<userinput>{review version}
2.5.0   @<balloon>{必ず「2.5.0」であること（より新しいバージョンは未サポート）}
//}

//note[macOS標準のRubyでは「gem install」がエラーになる]{
macOSには標準でRubyがインストールされていますが、それを使って「@<code>|gem install|」を実行するとエラーになります。

//terminal[][macOS標準のRubyではgemがインストールできない]{
$ gem install review --version=2.5
ERROR:  While executing gem ... (Gem::FilePermissionError)
    You don't have write permissions for the /Library/Ruby/Gems/2.3.0 directory.
//}

このエラーを回避するには、次のような方法があります。

 - (a) Homebrewなどを使って別のRubyをインストールする。
 - (b) @<file>{~/.gemrc}に「@<code>{install: --user-install}」という行を追加する。
 - (c) 「@<file>{rubygems/}」のようなフォルダを作り、そのパスを環境変数@<code>|$GEM_HOME|に設定する。

しかしRubyやコマンドラインに慣れていない初心者にとっては、どの方法も難しいでしょう。

そこで、(c)に相当する作業を自動的に行えるようにしました。
それが、Rubyに詳しくない初心者向けのコマンド「@<code>|rake setup:rubygems|」です。
詳しいことは@<file>{lib/tasks/starter.rake}の中の「@<code>|task :rubygems|」の定義を見てください。
また環境変数@<code>|$GEM_HOME|を設定するかわりに、@<file>{Rakefile}の冒頭で@<code>|Gem.path|を設定しています。

//}

==== MacTeXのインストール

次に、MacTeXをダウンロードします。MacTeXとは、macOS用のTeXLiveです。
MacTeXはサイズが大きい（約4GB）ので、本家ではなく以下のミラーサイトのどれかを使ってください。

 * @<href>{http://ftp.jaist.ac.jp/pub/CTAN/systems/mac/mactex/}@<br>{}
   > @<file>{mactex-20200407.pkg}
 * @<href>{http://ftp.kddilabs.jp/pub/ctan/systems/mac/mactex/}@<br>{}
   > @<file>{mactex-20200407.pkg}
 * @<href>{http://ftp.riken.go.jp/pub/CTAN/systems/mac/mactex/}@<br>{}
   > @<file>{mactex-20200407.pkg}

ダウンロードができたら、ダブルクリックしてインストールしてください。

インストールしたらTerminal.appで次のコマンドを入力し、動作を確認してください（各行の先頭にある「@<code>{$ }」は入力せず、それ以降のコマンドを入力してください）。

//terminal[][MacTeXのインストールができたことを確認]{
$ @<userinput>{which uplatex}     @<balloon>{下線が引かれたコマンドだけを入力すること}
/Library/TeX/texbin/uplatex
$ @<userinput>{uplatex --version} @<balloon>{下線が引かれたコマンドだけを入力すること}
e-upTeX 3.14159265-p3.8.1-u1.23-180226-2.6 (utf8.uptex) (TeX Live 2020)
...（省略）...
//}

実際の出力結果は上と少し違うはずですが、だいたい合っていればOKです。

最後に、MacTeXでヒラギノフォントを使うための準備が必要です（これをしないと、PDFファイルの日本語フォントが見るに耐えません）。
そのためには、以下のページから「Bibunsho7-patch-1.5-20200511.dmg」@<fn>{873gn}をダウンロードしてください。
//footnote[873gn][日付が最新のものを選んでください。2020年6月時点では「20200511」が最新です。]

 * @<href>{https://github.com/munepi/bibunsho7-patch/releases}

ダウンロードしたらダブルクリックして解凍し、「Patch.app」をダブルクリックしてください。


=== Windowsを使っている場合

Windowsにおいて、RubyとTeXLiveをインストールする方法を説明します。

==== Rubyのインストール

以下のページにアクセスし、「Ruby+Devkit 2.7.3-1」をダウンロードしてインストールしてください。
x64版とx86版の2つがあるので、お使いのWindowsが64bit版ならx64版を、32bit版または不明ならx86版をダウンロードしてください。

 * @<href>{https://rubyinstaller.org/downloads/}

インストールしたら、コマンドプロンプトで以下のコマンドを入力し、Rubyが実行できることを確かめてください。

//terminal[][Rubyが実行できることを確認]{
C:\Users\yourname> @<userinput>{ruby --version}  @<balloon>{「ruby --version」だけを入力}
ruby 2.7.3-1 [x64-mingw32]
//}

実際の出力結果は上と少し違うでしょうが、だいたい合っていればOKです。

また以下のコマンドを実行し、必要なライブラリをインストールします。

//terminal[][必要なライブラリをインストール]{
C:\Users\yourname> @<userinput>{gem install review --version=2.5}
C:\Users\yourname> @<userinput>{review version}
2.5.0   @<balloon>{必ず「2.5.0」であること（より新しいバージョンは未サポート）}
//}

==== TeXLiveのインストール

次に、Windows用のTeXLiveをインストールします。詳しくはこちらのページを参照してください。
このうち、手順(16)において右上の「すべて」ボタンを押してください（つまりすべてのパッケージを選ぶ）。

 * 「TeXLive2020をインストールしてLaTeXを始める」
   @<br>{}@<href>{https://tm23forest.com/contents/texlive2020-install-latex-begin}

インストールできたら、コマンドプロンプトで以下のコマンドを実行してみてください。

//terminal[][コマンドが実行できることを確認]{
C:\Users\yourname> @<userinput>{uplatex --version} @<balloon>{「uplatex --version」だけを入力}
e-upTeX 3.14159265-p3.7.1-u1.22-161114-2.6 (utf8.uptex) (TeX Live 2020/W32TeX)
...（以下省略）...
//}

実際の出力結果は上と少し違うでしょうが、だいたい合っていればOKです。


== プロジェクトを作成

RubyとTeXLiveをインストールしたら、次に本を作るための「プロジェクト」を作成しましょう。

以下のWebサイトにアクセスしてください。

 * @<href>{https://kauplan.org/reviewstarter/}

アクセスしたら、画面の指示に従って操作をしてください（詳細は省略します）。
するとプロジェクトが作成されて、zipファイルがダウンロードできます。

以降では、プロジェクトのzipファイル名が「@<file>{mybook.zip}」だったとして説明します。


=={sec-generatesample} サンプルのPDFファイルを生成

プロジェクトのzipファイルをダウンロードしたら、解凍してサンプルのPDFファイルを生成してみましょう。

==={subsec-indocker} Dockerの場合

Dockerを使う場合は、次のような手順でサンプルのPDFファイルを生成してみましょう。

//terminal[][Dockerを使ってPDFファイルを生成する]{
$ @<userinput>{unzip mybook.zip}           @<balloon>{zipファイルを解凍}
$ @<userinput>{cd mybook/}                 @<balloon>{ディレクトリを移動}
$ @<userinput>{docker run --rm -v $PWD:/work -w /work kauplan/review2.5 rake pdf}
$ @<userinput>{ls *.pdf}                   @<balloon>{PDFファイルが生成できたことを確認}
mybook.pdf
//}

これでPDFファイルが生成されるはずです。生成できなかった場合は、Twitterで「@<em>{#reviewstarter}」タグをつけて質問してください（相手先不要）。

Dockerを使ってPDFファイルが作成できることを確認したら、このあとはdockerコマンドを使わずとも「@<code>{rake docker:pdf}」だけでPDFファイルが生成できます。

//terminal[][より簡単にPDFファイルを生成する]{
$ @<del>{docker run --rm -v $PWD:/work -w /work kauplan/review2.5 rake pdf}
$ @<userinput>{@<b>{rake docker:pdf}}            @<balloon>{これだけでPDFファイルが生成される}
//}

//note[もっと簡単にPDFファイルを生成するためのTips]{

環境変数「@<code>{$RAKE_DEFAULT}」を設定すると、引数なしの「@<code>{rake}」コマンドだけでPDFファイルが生成できます。

//terminal[][環境変数「@<code>{$RAKE_DEFAULT}」を設定する]{
$ @<userinput>{export RAKE_DEFAULT="docker:pdf"} @<balloon>{環境変数を設定}
$ @<del>{rake docker:pdf}
$ @<userinput>{rake}                  @<balloon>{「rake docker:pdf」が実行される}
//}

またシェルのエイリアス機能を使うと、コマンドを短縮名で呼び出せます。

//terminal[][シェルのエイリアス機能を使う]{
$ @<userinput>{alias pdf="rake docker:pdf"} @<balloon>{エイリアスを設定}
$ @<userinput>{pdf}                   @<balloon>{「rake docker:pdf」が実行される}
//}

//}


=== macOSの場合

macOSを使っている場合は、Terminal.app@<fn>{qqyo5}を開いて以下のコマンドを実行してください。
ここで、各行の先頭にある「@<code>{$ }」は入力せず、それ以降のコマンドを入力してください。
//footnote[qqyo5][繰り返しになりますが、Terminal.appはファインダで「アプリケーション」フォルダ > 「ユーティリティ」フォルダ > 「ターミナル」をダブルクリックすると起動できます。]

//terminal[][PDFファイルを生成する]{
$ @<userinput>{unzip mybook.zip}       @<balloon>{zipファイルを解凍し、}
$ @<userinput>{cd mybook/}             @<balloon>{ディレクトリを移動}
$ @<userinput>{rake pdf}               @<balloon>{PDFファイルを生成}
$ @<userinput>{ls *.pdf}               @<balloon>{PDFファイルが生成されたことを確認}
mybook.pdf
$ @<userinput>{open mybook.pdf}        @<balloon>{PDFファイルを開く}
//}

これでPDFファイルが生成されるはずです。生成できなかった場合は、Twitterで「@<em>{#reviewstarter}」タグをつけて質問してください（相手先不要）。

//note[もっと簡単にPDFファイルを生成するためのTips]{

環境変数「@<code>{$RAKE_DEFAULT}」を設定すると、引数なしの「@<code>{rake}」コマンドだけでPDFファイルが生成できます。

//terminal[][環境変数「@<code>{$RAKE_DEFAULT}」を設定する]{
$ @<userinput>{export RAKE_DEFAULT="pdf"} @<balloon>{環境変数を設定}
$ @<del>{rake pdf}
$ @<userinput>{rake}                      @<balloon>{「rake pdf」が実行される}
//}

またシェルのエイリアス機能を使うと、コマンドを短縮名で呼び出せます。

//terminal[][シェルのエイリアス機能を使う]{
$ @<userinput>{alias pdf="rake pdf"}      @<balloon>{エイリアスを設定}
$ @<userinput>{pdf}                       @<balloon>{「rake pdf」が実行される}
//}

//}


=== Windowsの場合

Windowsを使っている場合は、まずプロジェクトのzipファイル（@<file>{mybook.zip}）をダブルクリックして解凍してください。

そしてコマンドプロンプトで以下のコマンドを実行してください。

//terminal[][PDFファイルを生成する]{
C:\Users\yourname> @<userinput>{cd mybook}        @<balloon>{解凍してできたフォルダに移動}
C:\Users\yourname\mybook> @<userinput>{rake pdf}  @<balloon>{PDFファイルを生成}
C:\Users\yourname\mybook> @<userinput>{dir *.pdf} @<balloon>{PDFファイルが生成されたことを確認}
//}

これでPDFファイルが生成されるはずです。生成できなかった場合は、Twitterで「@<em>{#reviewstarter}」タグをつけて質問してください（相手先不要）。


== 注意点

エラーが発生したときは、@<secref>{02-tutorial|subsec-compileerror}の説明を参考にしてください。

そのほか、次の点に注意してください。

 * HTMLファイルを生成するときは「@<code>{rake web}」（または「@<code>{rake docker:web}」）を実行してください。
 * ePubファイルを生成するときは「@<code>{rake epub}」（または「@<code>{rake docker:epub}」）を実行してください。
 * Markdownファイルを生成するときは「@<code>{rake markdown}」（または「@<code>{rake docker:markdown}」）を実行してください。
 * Starterでは「@<code>{review-pdfmaker}」コマンドや「@<code>{review-epubmaker}」コマンドが使えません（実行はできますが望ましい結果にはなりません）。
   必ず「@<code>{rake pdf}」や「@<code>{rake epub}」を使ってください。

繰り返しになりますが、エラーが発生したときは@<secref>{02-tutorial|subsec-compileerror}の説明を読んでみてください。
