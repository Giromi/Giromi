
vim.cmd [[
  autocmd FileType javascript setlocal ts=2 sts=2 sw=2
  autocmd FileType typescript setlocal ts=2 sts=2 sw=2
  autocmd FileType typescriptreact setlocal ts=2 sts=2 sw=2
  autocmd FileType typescript.tsx setlocal ts=2 sts=2 sw=2
  autocmd FileType html setlocal ts=2 sts=2 sw=2
  autocmd FileType lua setlocal ts=2 sts=2 sw=2
]]

vim.wo.number 				        = true
vim.opt.tabstop 			        = 4
vim.opt.shiftwidth 		        = 4
vim.opt.smarttab 			        = true
vim.opt.expandtab			        = true
vim.opt.smartindent			      = true
vim.opt.clipboard 			      = 'unnamedplus'
vim.opt.relativenumber	      = true
vim.opt.mouse                 = 'a'
vim.opt.colorcolumn 		      = "80"
vim.opt.termguicolors 	      = true

vim.api.nvim_create_autocmd("BufWinEnter", {
    pattern = "*.*",
    command = "silent! loadview"
})

vim.api.nvim_create_autocmd("BufWinLeave", {
    pattern = "*.*",
    command = "mkview"
})

vim.g.python3_host_prog       = "/opt/homebrew/bin/python3"
