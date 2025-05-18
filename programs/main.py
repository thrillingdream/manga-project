from z3 import *

# 人物
Rinne = StringVal("Rinne")
Kacho = StringVal("Kacho")

# ソルバー初期化
s = Solver()

# 非決定なパラメータ
Stock = Int('Stock')          # 傘の在庫数（0以上）
RainToday = Bool('RainToday') # 雨が降るかどうか（True/False）

# 関数定義
IsEmployee = Function('IsEmployee', StringSort(), BoolSort())
CanBorrowUmbrella = Function('CanBorrowUmbrella', StringSort(), BoolSort())
HasUmbrella = Function('HasUmbrella', StringSort(), BoolSort())
IsDry = Function('IsDry', StringSort(), BoolSort())

# 制約：傘の在庫は0本以上
s.add(Stock >= 0)

# りんねと課長は社員
s.add(IsEmployee(Rinne) == True)
s.add(IsEmployee(Kacho) == True)

# 傘が借りられる ⇔ 社員であり、在庫が1本以上
x = String('x')
s.add(ForAll([x], CanBorrowUmbrella(x) == And(IsEmployee(x), Stock >= 1)))

# 傘を借りられるなら持っている（片方向制約）
s.add(ForAll([x], Implies(CanBorrowUmbrella(x), HasUmbrella(x))))

# 課長は常に傘を持っている（特別処理：相合傘用）
s.add(HasUmbrella(Kacho) == True)

# りんねが濡れない条件：雨が降らない ∨ 自分が傘持ってる ∨ 課長が傘持ってる
# s.add(IsDry(Rinne) == Or(Not(RainToday), HasUmbrella(Rinne), HasUmbrella(Kacho)))
s.add(IsDry(Rinne) == Or(Not(RainToday), HasUmbrella(Rinne)))


# === チェック：りんねが濡れる状況が存在するか ===
s.push()
s.add(IsDry(Rinne) == False)

result = s.check()
if result == sat:
    print("りんねが濡れてしまう状況が存在します（反例あり）")
    m = s.model()
    print(f"RainToday = {m[RainToday]}")
    print(f"Stock = {m[Stock]}")
    print(f"CanBorrowUmbrella(Rinne) = {m.evaluate(CanBorrowUmbrella(Rinne))}")
    print(f"HasUmbrella(Rinne) = {m.evaluate(HasUmbrella(Rinne))}")
    print(f"HasUmbrella(Kacho) = {m.evaluate(HasUmbrella(Kacho))}")
else:
    print("どんな条件でもりんねは濡れません（IsDry=True が常に成立）")
