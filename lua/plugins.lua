 -- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`

vim.cmd [[packadd packer.nvim]]

function get_setup(name)
   return require("config/" .. name)
end

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'
  use "lukas-reineke/lsp-format.nvim"

  use {
    'EdenEast/nightfox.nvim', 
    config = get_setup("nightfox")
  }

  -- A File Explorer For Neovim Written In Lua
  use {
    'nvim-tree/nvim-tree.lua',
    requires = {
      'nvim-tree/nvim-web-devicons', -- optional
    },
    config = get_setup("tree")
  }

  -- A blazing fast and easy to configure Neovim statusline written in Lua.
  use {
    'nvim-lualine/lualine.nvim',
    requires = { 'nvim-tree/nvim-web-devicons', opt = true },
    config = get_setup("lualine")

  }

  use {
    'akinsho/bufferline.nvim',
    tag = "*", 
    requires = 'nvim-tree/nvim-web-devicons',
    config = get_setup("bufferline")
  }

  use {
    'nvim-treesitter/nvim-treesitter',
    run = function()
      local ts_update = require('nvim-treesitter.install').update({ with_sync = true })
      ts_update()
    end,
  }

  use {
    'numToStr/Comment.nvim',
    config = get_setup("comment")
  }

  use "nvim-lua/plenary.nvim"

  use {
    'nvim-telescope/telescope.nvim',
    requires = { 'nvim-lua/plenary.nvim' },
    config = get_setup("telscope")
  }

  use {
    "folke/trouble.nvim",
    requires = { 
      "nvim-tree/nvim-web-devicons"
    },
    config = get_setup("trouble")
  }


  use {
    "jose-elias-alvarez/null-ls.nvim",
    requires = {
      'nvim-telescope/telescope.nvim',
      "folke/trouble.nvim",
    },
    config = get_setup("null-ls")
  }

  use {
    'MunifTanjim/eslint.nvim',
    requires = {
      "jose-elias-alvarez/null-ls.nvim",
    },
    config = get_setup("eslint")
  }

  use {
    'neovim/nvim-lspconfig',
    config = get_setup("lsp")
  }

 -- 자동으로 플러그인 찾아줌
  use {
    "williamboman/mason.nvim",
    "williamboman/mason-lspconfig.nvim",
    config = get_setup("mason")
  }

  use {
    "hrsh7th/nvim-cmp",
    requires = {
      "hrsh7th/cmp-buffer", "hrsh7th/cmp-nvim-lsp",
      'quangnguyen30192/cmp-nvim-ultisnips', 'hrsh7th/cmp-nvim-lua',
      'octaltree/cmp-look', 'hrsh7th/cmp-path', 'hrsh7th/cmp-calc',
      'f3fora/cmp-spell', 'hrsh7th/cmp-emoji'
    }
  }

  use {
    "windwp/nvim-autopairs",
     config = get_setup("nvim-autopairs")
  }

  use {
    'daeyun/vim-matlab',
    -- 'do' 옵션은 Packer에는 없으므로, run을 사용하여 비슷하게 구현
    run = function()
        vim.api.nvim_command('UpdateRemotePlugins')
    end,
    config = get_setup('vim-matlab')
  }

  use { 
    "kiyoon/jupynium.nvim", 
    run = "pip3 install --user ." ,
    config = get_setup("jupynium")
  }

  use "sindrets/diffview.nvim"

  use { "HakonHarnes/img-clip.nvim", }
  use {
    'MeanderingProgrammer/render-markdown.nvim',
    dependencies = { 'nvim-treesitter/nvim-treesitter', 'echasnovski/mini.nvim' },
  }

  use { 
    "yetone/avante.nvim",
    requires = {
	    "nvim-treesitter/nvim-treesitter", "stevearc/dressing.nvim", "nvim-lua/plenary.nvim",
	    "MunifTanjim/nui.nvim", --- The below dependencies are optional
	    "nvim-tree/nvim-web-devicons", -- or echasnovski/mini.icons
	    "zbirenbaum/copilot.lua", -- for providers='copilot'
      -- "author/avante_lib", -- 실제 라이브러리의 GitHub 경로가 필요합니다
    },
    config = get_setup("avante")
  }

  use {
    'akinsho/toggleterm.nvim',
    tag = '*',
    config = get_setup("toggleterm")
  }


  -- use {
  --   'lewis6991/gitsigns.nvim',
  --   config = get_setup("gitsigns")
  -- }




  
  -- @ Only nvim user can use this plugin
  -- use {
  --   'azratul/live-share.nvim',
  --   requires = {'jbyuki/instant.nvim'},
  --   config = get_setup("live-share")
  -- }

  -- 느림
  -- use {'neoclide/coc.nvim', branch = 'release'}
end)
