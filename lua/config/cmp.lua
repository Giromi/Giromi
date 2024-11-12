-- `nvim-cmp` 설정 시작
local cmp = require('cmp')
local compare = cmp.config.compare


cmp.setup({
  preselect = cmp.PreselectMode.None,
  -- 스니펫 엔진 설정: `vsnip` 사용
  snippet = {
    expand = function(args)
      vim.fn["vsnip#anonymous"](args.body)
    end,
  },
  completion = {
    debounce = 100,  -- 디바운스 시간을 100ms로 조정
  },
  -- 윈도우 설정(주석 처리된 부분 제거)
  -- 키 매핑
  mapping = cmp.mapping.preset.insert({
    ["<C-p>"] = cmp.mapping.select_prev_item(),
    ["<C-n>"] = cmp.mapping.select_next_item(),
    ['<C-b>'] = cmp.mapping.scroll_docs(-4),
    ['<C-f>'] = cmp.mapping.scroll_docs(4),
    ['<C-Space>'] = cmp.mapping.complete(),
    -- ['<C-e>'] = cmp.mapping.abort(),
    ["<C-e>"] = cmp.mapping.close(),
    ["<CR>"] = cmp.mapping.confirm({
      behavior = cmp.ConfirmBehavior.Insert,
      select = false
    }),
  }),
  자동완성 소스
   sources = {
    -- { name = "jupynium", priority = 1000 },  -- consider higher priority than LSP
    { name = "LuaSnip" },
    { name = "path" },
    { name = "nvim_lsp", priority = 100 },
    { name = "buffer" },
  },
  sorting = {
    priority_weight = 1.0,
    comparators = {
      compare.score,            -- Jupyter kernel completion shows prior to LSP
      compare.recently_used,
      compare.locality,
      -- ...
    },
  },
})

-- 특정 파일타입(`gitcommit`)을 위한 설정
cmp.setup.filetype('gitcommit', {
  sources = cmp.config.sources({
    { name = 'git' },
    { name = 'buffer' },
  })
})

-- 커맨드 라인(`/`, `?`) 설정
cmp.setup.cmdline({ '/', '?' }, {
  mapping = cmp.mapping.preset.cmdline(),
  sources = {
    { name = 'buffer' }
  }
})

-- -- 커맨드 라인(`:`) 설정
-- cmp.setup.cmdline(':', {
--   mapping = cmp.mapping.preset.cmdline(),
--   sources = cmp.config.sources({
--     { name = 'path' }
--   }, {
--     { name = 'cmdline' }
--   })
-- })

-- LSP 설정: `capabilities` 설정을 통해 `nvim-cmp`와의 통합 개선
local capabilities = require('cmp_nvim_lsp').default_capabilities()
require('lspconfig')['rust_analyzer'].setup {capabilities = capabilities}
require('lspconfig')['tsserver'].setup {capabilities = capabilities}
require('lspconfig')['pyright'].setup {
  settings = {
    python = {
      analysis = {
        autoSearchPaths = true,
        diagnosticMode = 'workspace',
        useLibraryCodeForTypes = true
      }
    }
  },
  capabilities = capabilities
}
