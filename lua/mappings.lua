vim.g.mapleader = ','

-- 터미널 모드에서 Ctrl-<Leader>-n으로 나가기
vim.api.nvim_set_keymap('t', '<C-<leader>n>', '<C-\\><C-n>', { noremap = true, silent = true })

vim.keymap.set("n", "<C-s>", ":w<CR>")
vim.keymap.set("i", "<C-s>", "<ESC>:w!<CR>a")

vim.keymap.set("n", "<leader>q", ":bp<CR>")
vim.keymap.set("n", "<leader>w", ":bn<CR>")
vim.keymap.set("n", "<leader>x", ":bd<CR>")
vim.keymap.set("n", "<leader>X", ":bd!<CR>")
vim.keymap.set("n", "<leader>nt", ":NvimTreeToggle<CR>")
vim.keymap.set("n", "<Leader>ln", ":NullLsInfo<CR>")

local api = require('nvim-tree.api')
vim.keymap.set('n', '<leader>nt', api.tree.toggle, {noremap = true, silent = true})


local builtin = require('telescope.builtin')
vim.keymap.set('n', '<leader>ff', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})
vim.keymap.set('n', '<leader>fb', builtin.buffers, {})
vim.keymap.set('n', '<leader>fh', builtin.help_tags, {})

-- See `:help vim.diagnostic.*` for documentation on any of the below functions
vim.keymap.set('n', '<space>e', vim.diagnostic.open_float)
vim.keymap.set('n', '[d', vim.diagnostic.goto_prev)
vim.keymap.set('n', ']d', vim.diagnostic.goto_next)
vim.keymap.set('n', '<space>q', vim.diagnostic.setloclist)

-- Trouble start
local trouble = require("trouble")
vim.keymap.set("n", "<leader>xx", trouble.toggle)
vim.keymap.set("n", "<leader>xw", function() trouble.toggle("workspace_diagnostics") end)
vim.keymap.set("n", "<leader>xd", function() trouble.toggle("document_diagnostics") end)
vim.keymap.set("n", "<leader>xq", function() trouble.toggle("quickfix") end)
vim.keymap.set("n", "<leader>xl", function() trouble.toggle("loclist") end)
vim.keymap.set("n", "gR", function() trouble.toggle("lsp_references") end)
-- Trouble end



-- Gitsigns start
-- local gs = require('gitsigns')
-- vim.keymap.set('n', ']c', function()
--   if vim.wo.diff then return ']c' end
--   vim.schedule(function() gs.next_hunk() end)
--   return '<Ignore>'
-- end, {expr=true})
--
-- vim.keymap.set('n', '[c', function()
--   if vim.wo.diff then return '[c' end
--   vim.schedule(function() gs.prev_hunk() end)
--   return '<Ignore>'
-- end, {expr=true})
--
-- ㄴ Actions
-- vim.keymap.set('n', '<leader>hs', gs.stage_hunk)
-- vim.keymap.set('n', '<leader>hr', gs.reset_hunk)
-- vim.keymap.set('v', '<leader>hs', function() gs.stage_hunk {vim.fn.line('.'), vim.fn.line('v')} end)
-- vim.keymap.set('v', '<leader>hr', function() gs.reset_hunk {vim.fn.line('.'), vim.fn.line('v')} end)
-- vim.keymap.set('n', '<leader>hS', gs.stage_buffer)
-- vim.keymap.set('n', '<leader>hu', gs.undo_stage_hunk)
-- vim.keymap.set('n', '<leader>hR', gs.reset_buffer)
-- vim.keymap.set('n', '<leader>hp', gs.preview_hunk)
-- vim.keymap.set('n', '<leader>hb', function() gs.blame_line{full=true} end)
-- vim.keymap.set('n', '<leader>tb', gs.toggle_current_line_blame)
-- vim.keymap.set('n', '<leader>hd', gs.diffthis)
-- vim.keymap.set('n', '<leader>hD', function() gs.diffthis('~') end)
-- vim.keymap.set('n', '<leader>td', gs.toggle_deleted)

-- ㄴ Text object
vim.keymap.set({'o', 'x'}, 'ih', ':<C-U>Gitsigns select_hunk<CR>')

-- Gitsigns end
--
-- jupynium start
--[[
-- <space>x: Execute selected cells
-- <space>c: Clear selected cells
-- <PageUp>, <PageDown>: Scroll notebook
-- <space>js: Scroll to cell (if autoscroll is disabled)
-- <space>K: Hover (inspect a variable)
-- <space>jo: Toggle output scroll (when output is long)
]]


 vim.keymap.set(
    { "n", "x" },
    "<space>s",
    "<cmd>JupyniumLoadFromIpynbTabAndStartSync 2<cr>",
    { buffer = buf_id, desc = "Sync" }
 )

 vim.keymap.set(
    { "n", "x" },
    "<space>S",
    "<cmd>JupyniumStopSync<cr>",
    { buffer = buf_id, desc = "Sync" }
 )

--
--  vim.keymap.set(
--     { "n", "x" },
--     "<Esc>[1;5M",  -- Hex Code로 전달된 Ctrl + Enter의 시퀀스를 처리
--     "<cmd>:JupyniumExecuteSelectedCells<cr>",
--     { buffer = buf_id, desc = "Sync on Hex Code" }
-- )

-- Autocmd to handle .ju.py files
vim.api.nvim_create_autocmd("BufEnter", {
    pattern = "*.ju.py",
    callback = function()
        vim.keymap.set(
            { "n", "v", "x", "i" },
            "<Esc>[1;5M",  -- Hex Code for Ctrl + Enter
            function()
                -- Exit Insert mode if necessary
                if vim.fn.mode() == "i" then
                    vim.cmd("stopinsert")
                end
                -- Execute the command
                vim.cmd("JupyniumExecuteSelectedCells")
            end,
            { buffer = true, desc = "Sync on Hex Code for Jupynium" }
        )
    end,
})

-- Autocmd to handle .m files
vim.api.nvim_create_autocmd("BufEnter", {
    pattern = "*.m",
    callback = function()
        vim.keymap.set(
            { "n", "v", "x", "i" },
            "<Esc>[1;5M",  -- Hex Code for Ctrl + Enter
            function()
                -- Exit Insert mode if necessary
                if vim.fn.mode() == "i" then
                    vim.cmd("stopinsert")
                end
                -- Execute the command
                vim.cmd("MatlabCliRunCell")
            end,
            { buffer = true, desc = "Sync on Hex Code for MATLAB" }
        )
    end,
})
 -- [1;5는 Enter 키(1)가 Ctrl 키(5)와 함께 눌렸음
