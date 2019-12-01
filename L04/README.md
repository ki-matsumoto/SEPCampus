# DOTweenを使用してみよう
<div style="text-align: right;">
2019年11月13日<br>
株式会社アルファオメガ  松本清明
</div>


# DOTweenのインストール

## DOTween 公式サイト

<img width="640" alt="DOTween" src="img/DOTween.png">

[DOTween公式サイト](http://dotween.demigiant.com/)

## DOTween アセットのダウンロード

<img width="640" alt="DOTween_Download" src="img/DOTween2.png">

[Downloadサイトのリンク](http://dotween.demigiant.com/download.php/)

最新版 v1.2.305(2019/11/13現在)です。
DOTween_1_2_305.zipをダウンロードしてくだください。
又はダウンロードしてコピーしてありますので使用してください。

## インストール方法

## UnityHubで新規プロジェクトをつくります
<img width="640" alt="Unity1" src="img/Unity1.png">

## Unityの起動画面
<img width="640" alt="Unity2" src="img/Unity2.png">

### DOTween_1_2_305.zipの解凍
- DOTween_1_2_305.zipを展開して出てきたDOTweenフォルダーをUnityプロジェクトの Assetsにコピーします。

<img width="640" alt="Unity3" src="img/Unity3.png">

以下のダイアログが表示されます。

### Unityにインポート
<img width="320" alt="DOTween3" src="img/DOTween3.png">

- Open DOTween Unity Panelボタンを押します。

### DOTween Unity Panel ダイアログ
<img width="320" alt="DOTween4" src="img/DOTween4.png">

緑のボタンのSetup DOTween...を押します。


### DOTween Unity Panel ダイアログ
<img width="320" alt="DOTween5" src="img/DOTween5.png">

Applyを押します。
これでDOTweenが使用できるようになりました。


# DOTweenを使用してみよう

## シーンを作成

### Plane GameObjectを配置
UnityEditorのメニューで[GameOjbect]-[3D Object]-[Plane]を選んでPlaneを作成してください。
<img width="640" alt="Unity4" src="img/Unity4.png">


### Plane のマテリアルを変更

1. UnityEditorのメニューで[Assets]-[Create]-[Material]を選びます。
   <img width="640" alt="Unity5" src="img/Unity5.png">
1. マテリアル名をNew MaterialからPlaneMaterialに変更します。
1. マテリアルの色を変えてます。例ではグレーにしました。
1. Plane GameObjectにドロップして、マテリアルを変更します。
   <img width="640" alt="Unity6" src="img/Unity6.png">

### cube GameObjectを配置

1. UnityEditorのメニューで[GameOjbect]-[3D Object]-[Cube]を選び立方体を作成してください。
1. Placeオブジェクトに埋まっているので cubeのYの高さを0.5あげます。

### Cameraを変更

<img width="640" alt="Unity7" src="img/Unity7.png">

確認しやすいようにカメラを変更します。

例)

|パラメータ|X|Y|Z|
|:--|:--|:--|:--|
|Postion|0|5|-6|
|Rotation|42|0|0|
|Scale|1|1|1|

## Sample.csを作成
以下の様にSample.cs スクリプトを作成してください。

Sample.cs
```
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class Sample : MonoBehaviour {

	[SerializeField]
	GameObject CubeGameObject;

	// Use this for initialization
	void Start () {

	}

	// Update is called once per frame
	void Update () {

	}

	public void OnButtonDown()
	{
		this.CubeGameObject.transform.DOMove(new Vector3(3.0f, 0.5f, 0), 2.0f);
	}
}
```
## ボタンを用意する
1. UnityEditorのメニューで[GameOjbect]-[UI]-[Button]を選びます。
<img width="640" alt="Unity8" src="img/Unity8.png">

## Canvasにsample.csスクリプトを割り当てる
<img width="640" alt="Unity9" src="img/Unity9.png">
- 画像の赤の部分の様にCube GameObject のインスタンを設定します。


## ボタンに関数を割り当てる

画像の赤の部分の様にCanvasのオブジェクトを割り当ててSample.OnButtonDown関数を設定します。
<img width="640" alt="Unity10" src="img/Unity10.png">

## 動作確認
 UnityEditorで再生ボタンを押します。cubeが動いたでしょうか？
 うまく動作しなかった方は上から手順を見直して下さい。

# 最後に
色々なTweenがありますので、改造して色々な動きを作ってみて下さい。
