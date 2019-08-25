Misc = {
    Mailbox = {},
    Lightpost = {},
    Fountian = {},
    Tree ={}
}

function Misc.Mailbox.new(position)
    local entity = entityManager:createEntity()
    entity.name = "Mailbox_" .. entity.id
    local transform = entity:addTransform()
    transform.scale = Vector2.new(3, 3)
    if position ~= nil then
        transform.position = position
    end
    local sprite = entity:addSprite()
    sprite.texture_id = "pokemon_sheet"
    sprite.useTextureRect = true
    sprite.textureRect = IntRect.new(32, 128, 16, 32)
    
    return entity
end

function Misc.Lightpost.new(position)
    local entity = entityManager:createEntity()
    entity.name = "Lightpost_" .. entity.id
    local transform = entity:addTransform()
    if position ~= nil then
        transform.position = position
    end

    local bottomHalf = entityManager:createEntityOnParent(entity)
    bottomHalf.name = "Lightpost_" .. entity.id .. "_bottom_" .. bottomHalf.id
    local bottomTransform = bottomHalf:addTransform()
    bottomTransform.position = Vector3.new(0, 16, 0)
    local bottomSprite = bottomHalf:addSprite()
    bottomSprite.texture_id = "pokemon_sheet"
    bottomSprite.useTextureRect = true
    bottomSprite.textureRect = IntRect.new(240, 448, 16, 16)

    local topHalf = entityManager:createEntityOnParent(entity)
    topHalf.name = "Lightpost_" .. entity.id .. "_top_" .. topHalf.id
    local topTransform = topHalf:addTransform()
    topTransform.position = Vector3.new(0, 0, 2)
    local topSprite = topHalf:addSprite()
    topSprite.texture_id = "pokemon_sheet"
    topSprite.useTextureRect = true
    topSprite.textureRect = IntRect.new(240, 432, 16, 16)
    
    return entity 
end

function Misc.Fountian.new(position)
    local fountian = entityManager:createEntity()
    fountian.name = 'fountian_' .. fountian.id
    local transformCompfountian = fountian:addTransform()
    if position ~= nil then
        transformCompfountian.position = position
    end
    transformCompfountian.scale = Vector2.new(1, 1)
    transformCompfountian.rotation = 0

    local spriteCompfountian = fountian:addSprite()
    spriteCompfountian.texture_id = 'pokemon_sheet'
    spriteCompfountian.useTextureRect = true
    spriteCompfountian.textureRect = IntRect.new(0, 190, 80, 72)
end

function Misc.Tree.new(position)
    local tree = entityManager:createEntity()
    tree.name = 'tree_' .. tree.id
    local transformComptree = tree:addTransform()
    if position ~= nil then
        transformComptree.position = position
    end
    transformComptree.scale = Vector2.new(1, 1)
    transformComptree.rotation = 0

    local tree_top = entityManager:createEntityOnParent(tree)
    tree_top.name = 'tree_' .. tree.id .. '_top_' .. tree_top.id
    local transformComptree_top = tree_top:addTransform()
    transformComptree_top.position = Vector3.new(0, 0, 2)
    transformComptree_top.scale = Vector2.new(1, 1)
    transformComptree_top.rotation = 0

    local spriteComptree_top = tree_top:addSprite()
    spriteComptree_top.texture_id = 'pokemon_sheet'
    spriteComptree_top.useTextureRect = true
    spriteComptree_top.textureRect = IntRect.new(48, 288, 32, 32)

    local tree_bottom = entityManager:createEntityOnParent(tree)
    tree_bottom.name = 'tree_' .. tree.id .. '_bottom_' .. tree_bottom.id
    local transformComptree_bottom = tree_bottom:addTransform()
    transformComptree_bottom.position = Vector3.new(0, 32, 0)
    transformComptree_bottom.scale = Vector2.new(1, 1)
    transformComptree_bottom.rotation = 0

    local spriteComptree_bottom = tree_bottom:addSprite()
    spriteComptree_bottom.texture_id = 'pokemon_sheet'
    spriteComptree_bottom.useTextureRect = true
    spriteComptree_bottom.textureRect = IntRect.new(48, 320, 32, 16)
    
    return tree, tree_top, tree_bottom
end