# README

これは Re:VIEW Starter で生成された、Re:VIEW 用プロジェクトです。


## ユーザーズガイド

以下のサイトで「ユーザーズガイド」のPDFファイルをダウンロードできます。

- https://kauplan.org/reviewstarter/


## コンパイル方法

Docker を使う場合：

```terminal
$ docker pull kauplan/review2.5    # 3GB 以上ダウンロードするので注意
$ unzip omotech-manga-001.zip
$ cd omotech-manga-001/
$ docker run --rm -v $PWD:/work -w /work kauplan/review2.5 rake pdf
$ ## または rake docker:pdf でもOK
$ ls omotech-manga-001.pdf
```

Docker を使わない場合 (Ruby と Re:VIEW と LaTeX が必要)：

```terminal
$ gem install review --version 2.5  # 最初に1回だけ行う（2回目からは不要）
$ review version                    # Re:VIEWのバージョンを確認
2.5.0                               # （3系は未サポートなので注意!!）
$ unzip omotech-manga-001.zip
$ cd omotech-manga-001/
$ rake pdf
$ ls omotech-manga-001.pdf
```

これで「omotech-manga-001.pdf」が生成されます。


## 問い合わせ

Twitter でハッシュタグ「#reviewstarter」つきでツイートしてください。
