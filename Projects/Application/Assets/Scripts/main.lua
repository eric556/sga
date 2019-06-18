require("entities/player")
require("entities/pokemon_player")
require("tilemaps/tilemap")
require("tilemaps/pokemon_tilemap")
require("tilemaps/dungeon_tilemap")
require("entities/house")
require("entities/misc")

function magnitude(vec)
    return math.sqrt(vec.x * vec.x + vec.y * vec.y + vec.z + vec.z)
end

function movePlayer(dt)
    move = Vector3.new(0, 0, 0)

    if(getKeyDown(22)) then
        move = move + Vector3.new(0, -1, 0)
    elseif(getKeyDown(18)) then
        move = move + Vector3.new(0, 1, 0)
    elseif(getKeyDown(0)) then
        move = move + Vector3.new(-1, 0, 0)
    elseif(getKeyDown(3)) then
        move = move + Vector3.new(1, 0, 0)
    end

    if (move.x > 0 and move.y == 0) then
        playerSprite:setCurrentAnimation("right");
    elseif (move.x < 0 and move.y == 0) then
        playerSprite:setCurrentAnimation("left");
    elseif (move.x == 0 and move.y < 0) then
        playerSprite:setCurrentAnimation("up");
    elseif (move.x == 0 and move.y > 0) then
        playerSprite:setCurrentAnimation("down");
    elseif (move.x > 0 and move.y > 0) then
        -- playerSprite:setCurrentAnimation("down_right");
    elseif (move.x > 0 and move.y < 0) then
        -- playerSprite:setCurrentAnimation("up_right");
    elseif (move.x < 0 and move.y > 0) then
        -- playerSprite:setCurrentAnimation("down_left");
    elseif (move.x < 0 and move.y < 0) then
        -- playerSprite:setCurrentAnimation("up_left");
    else
        playerSprite:setCurrentAnimation("idle");
    end

    move = Normalize(move) * playerInput.speed * dt
    playerTransform.position = playerTransform.position + move
end

function load()
    player = PKPlayer.new()
    playerTransform = player:getTransform()
    playerSprite = player:getAnimatedSprite()
    playerInput = player:getInput()
    time = 0
    -- tilemap = makeTilemap()
    tilemap = Tilemap.load(pk_tilemap)
    tilemap2 = Tilemap.load(dungeon_tilemap)
    Houses.Blue.new(Vector3.new(531, 282, 0))
    Houses.Blue.new(Vector3.new(187, 282, 0))
    Misc.Mailbox.new(Vector3.new(633, 509, 0))
    Misc.Mailbox.new(Vector3.new(287, 509, 0))
end

function update(dt)
    movePlayer(dt)
end

function draw(dt)
    drawTilemap()
    drawSprite()
    drawAnimated(dt)
    drawShape()
end