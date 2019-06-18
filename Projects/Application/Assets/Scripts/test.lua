function load()
    entity = entityMangaer:createEntity()
    display = entity:addDisplay()
    transform = entity:addTransform()
    time = 0 
end

function draw(dt)
    drawShape()
end

function update(dt)
    transform.position = Vector3.new(600 + math.cos(time) * 400, 600 + math.sin(time) * 400, 0)
    time = time + dt
end