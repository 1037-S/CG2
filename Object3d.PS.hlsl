#include "Object3d.hlsli"

struct Material
{
    float32_t4 color;
    bool enebleLighting;
    //float32_t3 padding;
};

ConstantBuffer<Material> gMaterial : register(b0);

struct DirectionalLight //!< 平行光源
{
    float32_t4 color; //!< ライトの色
    float32_t3 direction; //!< ライトの向き
    float intensity; //!< 輝度
};

ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);


struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

Texture2D<float32_t4> gTexture : register(t0);
SamplerState gSampler : register(s0);


PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;

    float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);
    
   // output.color = gMaterial.color * textureColor;
    if (gMaterial.enebleLighting != 0)
    {
        float NdotL = dot(normalize(input.normal), -gDirectionalLight.direction);
        // 法線とライトの逆方向の内積から拡散反射の強度（cos）を計算
        float cos = pow(NdotL * 0.5f + 0.5f, 2.0f);
        // ライトの影響を加味した色を代入
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
  
    }
    else
    {
        // ライトが無効な場合はマテリアルの色×テクスチャの色
        output.color = gMaterial.color * textureColor;
    }
   
    
    return output;
}