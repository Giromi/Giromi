-- Automatic mappings disabled/enabled
-- vim.g.matlab_auto_mappings = 0 -- Disable automatic mappings
vim.g.matlab_auto_mappings = 1 -- Enable automatic mappings (Uncomment to enable)

-- Use g:matlab_server_launcher to control whether :MatlabLaunchServer uses a Vim or tmux split
-- vim.g.matlab_server_launcher = 'vim'  -- launch the server in a Neovim terminal buffer
vim.g.matlab_server_launcher = 'tmux' -- launch the server in a tmux split (Uncomment to use tmux)

-- Use g:matlab_server_split to control whether :MatlabLaunchServer uses a vertical or horizontal split
-- vim.g.matlab_server_split = 'vertical'   -- launch the server in a vertical split
vim.g.matlab_server_split = 'horizontal' -- launch the server in a horizontal split (Uncomment to use horizontal split)

