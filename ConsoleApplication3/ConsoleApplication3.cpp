﻿// ConsoleApplication3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
extern "C" int test();
#pragma comment(lib, "Dll1.lib")//インポートライブラリ
#include <Windows.h>

int main()
{
    std::cout << "Hello World!\n";
    //SetDllDirectoryA(R"(Y:\source\youtube-programmercpp\Y220127A_DLL_Fundamentals\x64\Debug)");
    if (const auto hModule = LoadLibraryA(R"(Y:\source\youtube-programmercpp\Y220127A_DLL_Fundamentals\x64\Debug\Dll1.dll)")) {
        std::cout << test() << '\n';
        FreeLibrary(hModule);
    }
    else {
        const auto error_code = GetLastError();
        std::cerr << "DLL1.dll の読み込みに失敗しました。エラーコードは " << error_code << "です。\n";
    }
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
