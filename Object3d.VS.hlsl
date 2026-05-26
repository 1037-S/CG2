struct VertexShaderOutput
{
    float32_t4 positon : SV_POSITION;
};

struct VertexShaderInput
{
    float32_t4 positon : POSITION;
};

VertexShaderOutput main(VertexShaderInput input)
{
    VertexShaderOutput outPut;
    outPut.positon = input.positon;
    return outPut;
}