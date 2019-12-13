# じゃんけんを作る
<div style="text-align: right;">
2019年12月14日<br>
株式会社アルファオメガ  松本清明
</div>

## Amazon ユーザーアカウント作成
AWSのユーザーアカウント登録を済ませておいて下さい。


## AWSのEC2にSSH接続

Windows10の場合
SSHクライアントを利用するのが良いと思います。自分は [RLogin](http://nanno.dip.jp/softlib/man/rlogin/)を利用しています。

Macなどその他の場合
``` bash
$ ssh -i ~/.ssh/秘密鍵名.pem ユーザ名@パブリックDNS
```

## OSを最新に更新
``` bash
$ sudo yum update -y
```
## nginxの設定

#＃# nginxをインストール
``` bash
$ sudo amazon-linux-extras install nginx1.12
$ nginx -v
nginx version: nginx/1.12.2
```
### nginx自動起動設定
``` bash
$ sudo systemctl start nginx.service
$ sudo systemctl enable nginx.service
$ systemctl status nginx.service
```

## PHP7.3の設定

### PHP7.3をインストール
``` bash
$ sudo amazon-linux-extras install php7.3 php-fpm
$ php-fpm -v
```

### PHP自動起動設定
``` bash
$ sudo systemctl start php-fpm.service
$ sudo systemctl enable php-fpm.service
$ systemctl status php-fpm.service
```

## 各種ファイルの準備

## index.htmlを用意
```html
<!DOCTYPE html>
<html lang="ja">
<head>
  <meta charset="utf-8">
  <title>シンプルHTML</title>
</head>
<body>
こんにちは
</body>
```

### echo.phpを用意
```PHP
<?php
$ary = array("code"=>0, "message"=>"Hello, world!",);
# json文字列を作成する
$result = json_encode($ary);
# json文字列を表示する
echo $result;
```

```PHP
<?php
// 0:グー, 1:チョキ, 2:パー
$computer = rand(0,2);
$you = $_GET['you'];
if( $you == $computer )
 $mes = "draw";
else if( ($you+1)%3 == $computer )
 $mes = "win";
else
 $mes = "loss";
$ary = array("computer"=>$computer, "message"=>$mes,);
$result = json_encode($ary);
echo $result;
```

出力されたjson
```
{"computer":2,"message":"win"}
```

## Unityクライアントを作る

ポイント
* UnityWebRequest
* JsonUtility
