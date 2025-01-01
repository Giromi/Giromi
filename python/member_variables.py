# my_func.py

class Champion:
    ### Static Variable
    game_end = False

    def __init__(self, name='아트록스', hp=100, ad=10):
        self.name = name
        self.hp = hp
        self.ad = ad

    def attack(self, enemy):
        enemy.hp -= self.ad
        my_print(f'{self.name}이(가) {enemy.name}을(를) 공격합니다.')

    def get_game_end_member_var(self):
        return self.game_end

    def get_gmae_end_static_var(self):
        return Champion.game_end


me = Champion('이즈리얼', 30, 30)
enemy = Champion('아트록스', 100, 10)


print(me.game_end)      # True 공유하는 변수
print(enemy.game_end)      # True 공유하는 변수


me.game_end = True # self.game_end = True
#
print('input self.game_end = True')
print(me.game_end)      # True 공유하는 변수
print(enemy.game_end)      # True 공유하는 변수

#
#
# Champion.game_end = True 
#
# print(me.game_end)      # True 공유하는 변수
# print(enemy.game_end)      # True 공유하는 변수
