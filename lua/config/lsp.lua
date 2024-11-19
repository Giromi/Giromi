
local function on_attach(client, buffer)
  -- This callback is called when the LSP is atttached/enabled for this buffer
  -- we could set keymaps related to LSP, etc here.
end

-- Setup language servers.
-- local lsp = require('lsp-zero').preset({})
-- lsp.on_attach(function(client, bufnr)
-- lsp.default_keymaps({buffer = bufnr})
-- end)

local lspconfig = require('lspconfig')
local servers = { 'pyright', 'ts_ls', 'clangd', 'eslint', 'matlab_ls'}

for _, lsp in pairs(servers) do
  require('lspconfig')[lsp].setup {
      on_attach = on_attach,
      flags = {
        debounce_text_changes = 150,
      }
  }
end


require'lspconfig'.matlab_ls.setup {
  -- cmd = { "/path/to/matlab-language-server", "--stdio" }, -- MATLAB Language Server 실행 경로
  filetypes = { "matlab" }, -- MATLAB 파일 유형
  root_dir = require('lspconfig.util').root_pattern(".git", "."),
  settings = {
    matlab = {
      installPath = "/Applications/MATLAB_R2024b.app", -- MATLAB 설치 경로
      mlint = {
        enable = true, -- MATLAB 코드 분석 활성화
      },
      workspace = {
        library = {}, -- 라이브러리 경로 설정
      }
    }
  }
}

-- Global mappings.
-- See `:help vim.diagnostic.*` for documentation on any of the below functions
vim.keymap.set('n', '<space>e', vim.diagnostic.open_float)
vim.keymap.set('n', '[d', vim.diagnostic.goto_prev)
vim.keymap.set('n', ']d', vim.diagnostic.goto_next)
vim.keymap.set('n', '<space>q', vim.diagnostic.setloclist)

-- Use LspAttach autocommand to only map the following keys
-- after the language server attaches to the current buffer
vim.api.nvim_create_autocmd('LspAttach', {
group = vim.api.nvim_create_augroup('UserLspConfig', {}),
callback = function(ev)
  -- Enable completion triggered by <c-x><c-o>
  vim.bo[ev.buf].omnifunc = 'v:lua.vim.lsp.omnifunc'

  -- Buffer local mappings.
  -- See `:help vim.lsp.*` for documentation on any of the below functions
  -- local opts = { buffer = ev.buf }
  local opts = { noremap=true, silent=true, buffer=bufnr }

  vim.keymap.set('n', 'gD', vim.lsp.buf.declaration, opts)
  vim.keymap.set('n', 'gd',     vim.lsp.buf.definition, opts)
  vim.keymap.set("n", "<c-]>",  vim.lsp.buf.definition, opts)
  vim.keymap.set('n', '<space>K', vim.lsp.buf.hover, opts)
  vim.keymap.set('n', 'gi', vim.lsp.buf.implementation, opts)
  vim.keymap.set('n', '<C-k>', vim.lsp.buf.signature_help, opts)
  vim.keymap.set('n', '<space>wa', vim.lsp.buf.add_workspace_folder, opts)
  vim.keymap.set('n', '<space>wr', vim.lsp.buf.remove_workspace_folder, opts)
  vim.keymap.set('n', '<space>wl', function()
    print(vim.inspect(vim.lsp.buf.list_workspace_folders()))
  end, opts)
  vim.keymap.set('n', '<space>D', vim.lsp.buf.type_definition, opts)
  vim.keymap.set('n', '<space>rn', vim.lsp.buf.rename, opts)
  vim.keymap.set({ 'n', 'v' }, '<space>ca', vim.lsp.buf.code_action, opts)
  vim.keymap.set('n', 'gr', vim.lsp.buf.references, opts)
  vim.keymap.set('n', '<space>f', function()
    vim.lsp.buf.format { async = true }
  end, opts)
end,
})

local signs = { Error = "✖", Warn = "⚠ ", Hint = "➤ ", Info = "ℹ " } 
for type, icon in pairs(signs) do
    local hl = "DiagnosticSign" .. type
    vim.fn.sign_define(hl, { text = icon, texthl= hl, numhl = hl })
end

vim.diagnostic.config({
  virtual_text = {
    -- source = "always",  -- Or "if_many"
    prefix = '■', -- Could be '▎', '●', 'x'
  },
  severity_sort = true,
  float = {
    source = "always",  -- Or "if_many"
  },
})

vim.diagnostic.config({
  virtual_text = false
})

-- Show line diagnostics automatically in hover window
vim.opt.updatetime = 250
vim.cmd [[autocmd CursorHold,CursorHoldI * lua vim.diagnostic.open_float(nil, {focus=false})]]



-- Set completeopt to have a better completion experience
-- :help completeopt
-- menuone: popup even when there's only one match
-- noinsert: Do not insert text until a selection is made
-- noselect: Do not auto-select, nvim-cmp plugin will handle this for us.
vim.o.completeopt = "menuone,noinsert,noselect"

-- Avoid showing extra messages when using completion
vim.opt.shortmess = vim.opt.shortmess + "c"

-- Configure LSP through rust-tools.nvim plugin.
-- rust-tools will configure and enable certain LSP features for us.
-- See https://github.com/simrat39/rust-tools.nvim#configuration

-- -- Rust를 위한 특별한 설정
-- local rust_opts = {
--   tools = {
--     runnables = {
--       use_telescope = true,
--     },
--     inlay_hints = {
--       auto = true,
--       show_parameter_hints = false,
--       parameter_hints_prefix = "",
--       other_hints_prefix = "",
--     },
--   },
--   server = {
--     on_attach = on_attach,
--     settings = {
--       ["rust-analyzer"] = {
--         checkOnSave = {
--           command = "clippy",
--         },
--       },
--     },
--   },
-- }
--
-- -- rust-tools 설정
-- require("rust-tools").setup(rust_opts)
--


-- vim.keymap.set("n", "<c-]>",  vim.lsp.buf.definition, keymap_opts)
-- vim.keymap.set("n", "gd",     vim.lsp.buf.definition, keymap_opts)
-- vim.keymap.set("n", "K", vim.lsp.buf.hover, keymap_opts)
-- vim.keymap.set("n", "gD", vim.lsp.buf.implementation, keymap_opts)
-- vim.keymap.set("n", "<c-k>", vim.lsp.buf.signature_help, keymap_opts)
-- vim.keymap.set("n", "1gD", vim.lsp.buf.type_definition, keymap_opts)
-- vim.keymap.set("n", "gr", vim.lsp.buf.references, keymap_opts)
-- vim.keymap.set("n", "g0", vim.lsp.buf.document_symbol, keymap_opts)
-- vim.keymap.set("n", "gW", vim.lsp.buf.workspace_symbol, keymap_opts)
--
