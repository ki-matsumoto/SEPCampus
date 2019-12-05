// MaruBatsuGame.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <iostream>
#include <cstdio>

enum class KindType
{
	Blank,	// 0:何もない
	Maru,	// 1:〇
	Batsu,	// 2:×
};
enum class ResultType
{
	Undecided,	// 0: 勝敗は決まっていない
	WinMaru,	// 1: 〇が勝ち
	WinBatsu,	// 2: ×が勝ち
	DrawGame,	// 3: 引き分け
};

static const int glidSize = 3;

//┌─┬─┬─┬─┬─┬─┬─┬─┐
//│b7│b6│b5│b4│b3│b2│b1│b0│
//├─┼─┼─┼─┼─┼─┼─┼─┤
//│　│　│　│　│　│　│×│〇│
//└─┴─┴─┴─┴─┴─┴─┴─┘
static KindType glid[glidSize][glidSize];

static int gamePhase;

// 関数定義
static void SelectGlid();
static bool CheckInputData(int x, int y);
static ResultType CheckGameResult();
static void DrawBoard();
static bool DrawResult(ResultType rType);

int main()
{
	gamePhase = 0;
	memset(glid, 0, sizeof(glid));

	bool exitFlag = false;
	printf_s("マルバツゲームスタートです。\n");
	while (exitFlag == false)
	{
		DrawBoard();
		ResultType rType;
		rType = CheckGameResult();
		DrawResult(rType);
		if (rType == ResultType::Undecided)
		{
			SelectGlid();
		}
		else
		{
			exitFlag = true;
		}
	}
	printf_s("マルバツゲームを終了します。\n");
}

static void SelectGlid()
{
	int x = 0, y = 0;
	printf_s("横の番号(1～3)を入力してください>");
	scanf_s("%d", &x);
	printf_s("縦の番号(1～3)を入力してください>");
	scanf_s("%d", &y);

	x--;y--;
	if (CheckInputData(x, y))
	{
		KindType kind;
		if ((gamePhase & 1) == 0)
		{
			kind = KindType::Maru;
		}
		else
		{
			kind = KindType::Batsu;
		}
		glid[y][x] = kind;
		gamePhase++;
	}
	// 数字ではなくそのほかの文字を入力した時のエラー処理
	rewind(stdin);
}

static ResultType ConvertGameResult(int data)
{
	switch (data)
	{
	case 1:
		return ResultType::WinMaru;
	case 2:
		return ResultType::WinBatsu;
	}
	return ResultType::Undecided;
}

// 0: 勝敗は決まっていない
// 1: 〇が勝ち
// 2: ×が勝ち
// 3: 引き分け
static ResultType CheckGameResult()
{
	// 行確認
	for (int y = 0; y < glidSize; y++)
	{
		int result = 3;
		for (int x = 0; x < glidSize; x++)
		{
			result &= static_cast<int>(glid[y][x]);
		}
		if (result != 0) return ConvertGameResult(result);
	}

	// 列確認
	for (int x = 0; x < glidSize; x++)
	{
		int result = 3;
		for (int y = 0; y < glidSize; y++)
		{
			result &= static_cast<int>(glid[y][x]);
		}
		if (result != 0) return ConvertGameResult(result);
	}

	// 左上から右下の線
	{
		int result = 3;
		for (int i = 0; i < glidSize; i++)
		{
			result &= static_cast<int>(glid[i][i]);
		}
		if (result != 0) return ConvertGameResult(result);
	}

	// 左下から右上の線
	{
		int result = 3;
		for (int i = 0; i < glidSize; i++)
		{
			result &= static_cast<int>(glid[glidSize - i - 1][i]);
		}
		if (result != 0) return ConvertGameResult(result);
	}

	// 勝敗は決まっていない
	for (int j = 0; j < glidSize; j++)
	{
		for (int i = 0; i < glidSize; i++)
		{
			if (glid[j][i] == KindType::Blank) return ResultType::Undecided;
		}
	}

	// 引き分け
	return ResultType::DrawGame;
}


static bool CheckInputData(int x, int y)
{
	if (!(x>=0 && x<glidSize))
	{
		printf_s("Xの範囲が間違っています\n");
		return false;
	}
	else if (!(y >= 0 && y < glidSize))
	{
		printf_s("Yの範囲が間違っています\n");
		return false;
	}
	else if (glid[y][x] != KindType::Blank)
	{
		printf_s("選ぶことが出来ません\n");
		return false;
	}
	return true;
}

static void DrawBoard()
{
	for (int y = 0; y < glidSize; y++)
	{
		puts("+--+--+--+");
		for (int x = 0; x < glidSize; x++)
		{
			const char* pieceMark;
			switch (glid[y][x])
			{
			case KindType::Maru:
				pieceMark = "〇";
				break;
			case KindType::Batsu:
				pieceMark = "×";
				break;
			default:
				pieceMark = "　";
				break;
			}
			printf_s("|%s", pieceMark);
		}
		puts("|");
	}
	puts("+--+--+--+");

//	printf_s("┌─┬─┬─┐\n");
//	printf_s("│  │  │  │\n");
//	printf_s("├─┼─┼─┤\n");
//	printf_s("│　│　│　│\n");
//	printf_s("├─┼─┼─┤\n");
//	printf_s("│　│　│　│\n");
//	printf_s("└─┴─┴─┘\n");
}

static bool DrawResult(ResultType rType)
{
	bool result = false;
	switch (rType)
	{
	case ResultType::Undecided:
		if ((gamePhase & 1) == 0)
		{
			printf_s("〇の番です\n");
		}
		else
		{
			printf_s("×の番です\n");
		}
		break;
	case ResultType::WinMaru:
		printf_s("〇が勝ちました。\n");
		result = true;
		break;

	case ResultType::WinBatsu:
		printf_s("×が勝ちました。\n");
		result = true;
		break;

	case ResultType::DrawGame:
		printf_s("引き分けでした。\n");
		result = true;
		break;
	}
	return result;
}


// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
