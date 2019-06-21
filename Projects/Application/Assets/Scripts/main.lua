require("entities/player")
require("entities/pokemon_player")
require("tilemaps/tilemap")
require("tilemaps/pokemon_tilemap")
require("tilemaps/dungeon_tilemap")
require("tilemaps/jubelife_tilemap")
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
    player.name = "Player"
    playerTransform = player:getTransform()
    playerSprite = player:getAnimatedSprite()
    playerInput = player:getInput()
    time = 0
    tilemap = Tilemap.load(jblife_tilemap)
    tilemap.name = "Tilemap"

    camera = entityManager:createEntity()
    camera.name = "Camera"
    cameraComp = camera:addCamera()
    cameraComp:setSize(298, 298)
    cameraComp:setFollow(player)

    -- setup scene
    Buildings.PkCenter.new(Vector3.new(1032, 641, 0))
    Buildings.ShoppingCenter.new(Vector3.new(401, 369, 0)) -- Vector3.new(592, 448, 2)
    Buildings.Apartment1.new(Vector3.new(592, 448, 3))
    Buildings.Apartment2.new(Vector3.new(592, 352, 2))
    Buildings.Apartment3.new(Vector3.new(1021, 449, 3))
    Buildings.Apartment2.new(Vector3.new(1020, 368, 0))
    Buildings.Apartment1.new(Vector3.new(1020, 287, 0))
    Buildings.Apartment4.new(Vector3.new(1137, 746, 1))
    Buildings.Apartment5.new(Vector3.new(1139, 670, 0))
    Buildings.Apartment4.new(Vector3.new(1137, 878, 3))
    Buildings.Apartment2.new(Vector3.new(1137, 1019, 4))
    Buildings.Apartment1.new(Vector3.new(1070, 1022, 5))
    Buildings.Apartment5.new(Vector3.new(815, 960, 2))
    Buildings.Apartment2.new(Vector3.new(736, 942, 2))
    Buildings.Apartment1.new(Vector3.new(736, 1024, 3))
    Buildings.Apartment4.new(Vector3.new(657, 946, 2))
    Buildings.Apartment2.new(Vector3.new(385, 845, 2))
    Buildings.Apartment5.new(Vector3.new(385, 960, 2))
    Buildings.Apartment4.new(Vector3.new(385, 701, 3))
    Buildings.Apartment4.new(Vector3.new(657, 701, 3))
    Buildings.Apartment1.new(Vector3.new(660, 639, 2))
    Buildings.Apartment2.new(Vector3.new(595, 663, 2))
    Buildings.Apartment2.new(Vector3.new(530, 663, 2))
    Buildings.Apartment2.new(Vector3.new(464, 663, 2))
    Buildings.Station.new(Vector3.new(731, 333, 0))
    Buildings.School.new(Vector3.new(770, 800, 2))
    Buildings.Gym.new(Vector3.new(488, 780, 3))
    Misc.Fountian.new(Vector3.new(465, 1006, 0))
    Misc.Fountian.new(Vector3.new(559, 1008, 0))
    Misc.Fountian.new(Vector3.new(809, 670, 0))
    Misc.Tree.new(Vector3.new(779, 677, 3))
    Misc.Lightpost.new(Vector3.new(1006, 496, 3))
    Misc.Lightpost.new(Vector3.new(910, 496, 3))
    Misc.Lightpost.new(Vector3.new(1003, 352, 3))
    Misc.Lightpost.new(Vector3.new(922, 352, 3))
    Misc.Lightpost.new(Vector3.new(1134, 556, 3))
    Misc.Lightpost.new(Vector3.new(1134, 637, 3))
    Misc.Lightpost.new(Vector3.new(1008, 669, 3))
    Misc.Lightpost.new(Vector3.new(913, 669, 3))
    Misc.Lightpost.new(Vector3.new(913, 831, 3))
    Misc.Lightpost.new(Vector3.new(1008, 831, 3))
    Misc.Lightpost.new(Vector3.new(913, 1086, 3))
    Misc.Lightpost.new(Vector3.new(1008, 1086, 3))


end

function update(dt)
    movePlayer(dt)
    updateCamera()
end

function draw(dt)
    drawTilemap()
    drawSprite()
    drawAnimated(dt)
    drawShape()
    checkCollisions()
end