// Validator_Practice3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include "IValidator.h"
#include "AndValidators.h"
#include "OrValidators.h"
#include "IsDigit.h"
#include "GreaterThan.h"
#include "LessThan.h"


int main()
{
    std::cout << "Hello World!\n";

    {
        AndValidators and1;
        and1.Add(IsDigit());
        and1.Add(GreaterThan(1));
        and1.Add(LessThan(3));
        
        AndValidators and2;
        and2.Add(IsDigit());
        and2.Add(GreaterThan(5));
        and2.Add(LessThan(8));

        // 数値 1~3 or 5~8ならOK
        OrValidators v;
        v.Add(and1);
        v.Add(and2);
        
        for (int i = 0; i < 10; i++)
        {
            ValidationResult res;
            char ch[32];
            sprintf_s( ch, "%d", i);
            std::cout << i;
            std::cout << (v.Eval(ch, res) ? " OK" : " NG");
            std::cout << std::endl;
        }
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
