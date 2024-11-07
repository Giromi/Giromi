 -- This file can be loaded by calling `lua require('plugins')` from your init.vim

-- Only required if you have packer configured as `opt`
vim.cmd [[packadd packer.nvim]]

function get_setup(name)
   return require("setup/" .. name)
end

return require('packer').startup(function(use)
  -- Packer can manage itself
  use 'wbthomason/packer.nvim'
  use "lukas-reineke/lsp-format.nvim"

  use {
      'EdenEast/nightfox.nvim', 
    -- config = get_setup("nightfox") 
    }

  -- A File Explorer For Neovim Written In Lua
  use {
    'nvim-tree/nvim-tree.lua',
    requires = {
      'nvim-tree/nvim-web-devicons', -- optional
    },
    -- config = get_setup("tree")
  }

  -- A blazing fast and easy to configure Neovim statusline written in Lua.
  use {
    'nvim-lualine/lualine.nvim',
    requires = { 'nvim-tree/nvim-web-devicons', opt = true },
    -- config = get_setup("lualine")

  }

  use {
    'akinsho/bufferline.nvim',
    tag = "*", 
    requires = 'nvim-tree/nvim-web-devicons',
    -- config = get_setup("bufferline")
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
    -- config = get_setup("comment")
  }

  use {
    'MunifTanjim/eslint.nvim',
    requires = {
      "jose-elias-alvarez/null-ls.nvim",
      'neovim/nvim-lspconfig',
    },
    -- config = get_setup("eslint")
  }

  use {
      'neovim/nvim-lspconfig',
    -- config = get_setup("lsp")
  }

  -- 자동으로 플러그인 찾아줌
  use {
    "williamboman/mason.nvim",
    "williamboman/mason-lspconfig.nvim",
    -- config = get_setup("mason")
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
    "jose-elias-alvarez/null-ls.nvim",
    "nvim-lua/plenary.nvim",
    -- config = get_setup("null-ls")
  }

  use {
	"windwp/nvim-autopairs",
    -- config = get_setup("nvim-autopairs")
  }
end)
