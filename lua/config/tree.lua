vim.g.loaded_netrw = 1
vim.g.loaded_netrwPlugin = 1
-- nvim-tree.filters.dotfiles = true


local function open_nvim_tree(data)

  -- buffer is a real file on the disk
  local real_file = vim.fn.filereadable(data.file) == 1

  -- buffer is a [No Name]
  local no_name = data.file == "" and vim.bo[data.buf].buftype == ""

  if not real_file and not no_name then
    return
  end

  -- open the tree, find the file but don't focus it
  require("nvim-tree.api").tree.toggle({ focus = false, find_file = true, })
end

vim.api.nvim_create_autocmd({ "VimEnter" }, { callback = open_nvim_tree })

require("nvim-tree").setup {
  sort_by = "case_sensitive",
  view = {
    width = 25,
    adaptive_size = false, -- 글자수에 맞게 사이즈 조절
    preserve_window_proportions = true,
    relativenumber = true,
  },
  renderer = {
    group_empty = true,
  },
  filters = {
    dotfiles = true,
  },
  diagnostics = {
    enable = true,
  },
}


