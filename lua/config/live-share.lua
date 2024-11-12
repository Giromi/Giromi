
vim.g.instant_username = "Giromi"

require("live-share").setup({
  port_internal = 8765, -- The local port to be used for the live share connection
  max_attempts = 20, -- Maximum number of attempts to read the URL from service(serveo.net or localhost.run), every 250 ms
  service_url = "/tmp/service.url", -- Path to the file where the URL from serveo.net will be stored
  service_pid = "/tmp/service.pid", -- Path to the file where the PID of the SSH process will be stored
  service = "locahost.run", -- Service to use, options are serveo.net or localhost.run
})
