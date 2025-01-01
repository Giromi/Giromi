# %%
!sudo apt-get install -y fonts-nanum
!sudo fc-cache -fv
!rm ~/.cache/matplotlib -rf

# 메뉴 -> 런타임 재시작하기

# %%
import matplotlib.pyplot as plt
# %matplotlib inline

plt.rc('font', family='NanumBarunGothic')
plt.rc('axes', unicode_minus=False)

from IPython.display import set_matplotlib_formats
# %config InlineBackend.figure_format = 'retina'

# %%
'''
본인의 코드 아래 추가
'''

# %%
''' 예시 '''
import numpy as np
import pandas as pd
import random
np.random.seed(seed=1)
group_list = ['사건1','사건2','사건3','사건4']
n_size = 20
group = [random.choice(group_list) for i in range(n_size)]
xval = np.random.poisson(lam=10,size=n_size)
label = np.random.binomial(n=1, p=0.5, size=n_size)
label = list(map(str, label))
df = pd.DataFrame({'group':group, 'xval':xval})
df.head()

df.plot.bar(x='group', y='xval') # matplotlib와 연동되는 것
df.plot.barh(x='group', y='xval') # 이게 좀 더 보기 좋을듯 합니다.

# %%
