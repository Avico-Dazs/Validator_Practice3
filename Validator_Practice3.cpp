// Validator_Practice3.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include "IValidator.h"
#include "AndValids.h"
#include "OrValids.h"
#include "IsDigit.h"
#include "GreaterThan.h"
#include "LessThan.h"
#include "PasswordValidFactory.h"

void Sample1()
{
    AndValids sub1;
    sub1.Add(IsDigit());
    sub1.Add(GreaterThan(1));
    sub1.Add(LessThan(3));

    AndValids sub2;
    sub2.Add(IsDigit());
    sub2.Add(GreaterThan(5));
    sub2.Add(LessThan(8));

    // 数値 1~3 or 5~8ならOK
    OrValids v;
    v.Add(sub1);
    v.Add(sub2);

    for (int i = 0; i < 10; i++)
    {
        ValidationResult res;
        char ch[32];
        sprintf_s(ch, "%d", i);
        std::cout << i;
        std::cout << (v.Eval(ch, res) ? " OK" : " NG");
        std::cout << std::endl;
    }
}

void Sample_PasswordValidFactory()
{
    std::cout << "Sample_PasswordValidFactory" << std::endl;
    PasswordValidFactory factory;
    IValidator* validator = factory.Create(0, 0, 0);
    // --- これと同じ ---
    // AndValids *validator = new AndValids();
    // validator.Add(StringLength(6))
    // validator.Add(ExcludingChars(".,*()@\"\'-\."));
    
    ValidationResult result;

    // 評価OK
    std::cout << (validator->Eval("pass1", result) ? "OK" : "NG") << std::endl;

    // 文字数上限を超えている
    std::cout << (validator->Eval("1234567", result) ? "OK" : "NG") << std::endl;

    // 禁止文字列が入っている
    std::cout << (validator->Eval("123.45", result) ? "OK" : "NG") << std::endl;

    delete validator;
}

int main()
{
    std::cout << "Hello World!\n";

    Sample1();
    Sample_PasswordValidFactory();
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
