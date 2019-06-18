Tilemap = {}

function Tilemap.load(map)
    local entity = entityManager:createEntity()
    local transform = entity:addTransform()
    transform.position = Vector3.new(map.transform.x, map.transform.y, 0)
    transform.scale = Vector2.new(map.transform.scale_x, map.transform.scale_y)
    local tilemap = entity:addTilemap()
    tilemap.tilesetId = map.tileset.id
    local tile_defs = {}
    i = 1
    for y = 0, map.tileset.height - 1 do
        for x = 0, map.tileset.width - 1 do
            tile_defs[i] = { x=x * map.tileset.tileWidth, y=y * map.tileset.tileHeight, width=map.tileset.tileWidth, height=map.tileset.tileHeight}
            i = i + 1
        end
    end

    tilemap:setMap(map.map_def, tile_defs, map.tileset.indexOffset)
    return entity
end