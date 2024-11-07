vim.g.mapleader = ','

vim.keymap.set("n", "<C-s>", ":w<CR>")
vim.keymap.set("i", "<C-s>", "<ESC>:w!<CR>i")

vim.keymap.set("n", "<leader>q", ":bp<CR>")
vim.keymap.set("n", "<leader>w", ":bn<CR>")
vim.keymap.set("n", "<leader>x", ":bd<CR>")
vim.keymap.set("n", "<leader>X", ":bd!<CR>")
vim.keymap.set("n", "<leader>nt", ":NvimTreeToggle<CR>")
vim.keymap.set("n", "<Leader>ln", ":NullLsInfo<CR>")

