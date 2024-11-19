
-- MATLAB 서버 경로 설정
vim.g.matlab_server_path = "/Applications/MATLAB_R2024b.app/bin/matlab"

-- MATLAB 서버 실행 방식 (vim 또는 tmux 사용)
vim.g.matlab_server_launcher = 'vim'  -- 'vim' 또는 'tmux'로 변경 가능

-- Python 경로 설정

 vim.g.matlab_server_split = 'vertical' -- or 'vertical'

 vim.cmd("command! MatlabLaunchServer :MatlabLaunchServer")
