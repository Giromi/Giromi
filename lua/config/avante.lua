-- deps:
require('img-clip').setup ({
  -- use recommended settings from above
})
require('copilot').setup ({
  -- use recommended settings from above
})
require('render-markdown').setup ({
  -- use recommended settings from above
})
require('avante_lib').load()
require('avante').setup ({
  ---@alias Provider "claude" | "openai" | "azure" | "gemini" | "cohere" | "copilot" | string
  -- provider = "claude", -- Recommend using Claude
  provider = "openai", 
  auto_suggestions_provider = "copilot", -- Since auto-suggestions are a high-frequency operation and therefore expensive, it is recommended to specify an inexpensive provider or even a free provider: copilot
   -- Claude 설정
  claude = {
    endpoint = "https://api.anthropic.com", -- Claude API 엔드포인트
    model = "claude-3-5-sonnet-20240620", -- Claude 모델 설정
    temperature = 0, -- 응답의 일관성 유지 (0은 예측 가능한 답변 제공)
    max_tokens = 4096, -- 한 번에 처리할 수 있는 최대 토큰 수
  },

  -- OpenAI 설정 (GPT-3.5를 사용할 수 있도록 함께 설정)
  openai = {
    -- api_key = "", -- OpenAI API 키 (보안을 위해 환경 변수로 설정 권장)
    model = "gpt-4o-mini", -- 비용 효율적인 모델인 GPT-3.5 사용
    temperature = 0.5, -- 창의성과 일관성의 균형을 맞추기 위한 설정
    max_tokens = 2048, -- 한 번에 처리할 수 있는 최대 토큰 수
  },


  behaviour = {
    auto_suggestions = false, -- Experimental stage
    auto_set_highlight_group = true,
    auto_set_keymaps = true,
    auto_apply_diff_after_generation = false,
    support_paste_from_clipboard = false,
  },
  mappings = {
    --- @class AvanteConflictMappings
    diff = {
      ours = "co",
      theirs = "ct",
      all_theirs = "ca",
      both = "cb",
      cursor = "cc",
      next = "]x",
      prev = "[x",
    },
    suggestion = {
      accept = "<Tab>",
      -- accept = "<M-l>",
      next = "<M-]>",
      prev = "<M-[>",
      dismiss = "<C-]>",
    },
    jump = {
      next = "]]",
      prev = "[[",
    },
    submit = {
      normal = "<CR>",
      insert = "<CR>",
    },
    sidebar = {
      -- switch_windows = "<Tab>",
      -- reverse_switch_windows = "<S-Tab>",
    },
  },
  hints = { enabled = true },
  windows = {
    ---@type "right" | "left" | "top" | "bottom"
    position = "right", -- the position of the sidebar
    wrap = true, -- similar to vim.o.wrap
    width = 30, -- default % based on available width
    sidebar_header = {
      align = "center", -- left, center, right for title
      rounded = true,
    },
  },
  highlights = {
    ---@type AvanteConflictHighlights
    diff = {
      current = "DiffText",
      incoming = "DiffAdd",
    },
  },
  --- @class AvanteConflictUserConfig
  diff = {
    autojump = true,
    ---@type string | fun(): any
    list_opener = "copen",
  },
  -- Your config here!
})
