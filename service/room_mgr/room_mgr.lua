local id_mgr = require "id_mgr"
local room = require "room"

local M = {}

function M:init()
    id_mgr:init()
    self.room_tbl = {}
    self.player_2_room = {}
    self.ready_tbl = {}
end

function M:create(game_id, player_info)
    local id = id_mgr:gen_id(game_id)
    self.room_tbl[id] = room.new(id, game_id, player_info)
    self.player_2_room[player_info.account] = id
    return id
end

function M:join(room_id, player_info)
    local room = self.room_tbl[room_id]
    if not room then
        return false
    end

    room:add(player_info)

    return true
end

function M:close(room_id)
    local room = self.room_tbl[room_id]
    self.room_tbl[room_id] = nil
    for _,v in ipairs(room.player_tbl) do
        self.player_2_room[v.account] = nil
    end
end

function M:get_room_by_player(account)
    local id = self.player_2_room[account]
    if not id then
        return
    end

    return self.room_tbl[id]
end

function M:add_ready(room)
    self.ready_tbl[room.id] = room
end

function M:check_ready()
    print("check_ready")
    for id, room in pairs(self.ready_tbl) do
        if room:start() then
            self:close(id)
        end
    end
end

return M
